import java.util.*;
import java.io.*;

public class clocktree {
	static Node[] arr;
	
	static class Node {
		public ArrayList<Integer> adj;
		public int val, testval;
		public Node(int v) {
			val = testval = v;
			adj = new ArrayList<Integer>();
		}
	}
	
	static void dfs(int cur, int prev) {
		for (int node : arr[cur].adj) {
			if (node == prev) continue;
			dfs(node, cur);
		}
		if (prev != -1) {
			arr[prev].testval+= 12 - arr[cur].testval;
			arr[prev].testval%= 12;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("clocktree.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("clocktree.out"));
		
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter pw = new PrintWriter(System.out);
		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new Node[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new Node(Integer.parseInt(st.nextToken()));
			if (arr[i].testval == 12) arr[i].testval = arr[i].val = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
			arr[a - 1].adj.add(b - 1);
			arr[b - 1].adj.add(a - 1);
		}
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			dfs(i, -1);
			if (arr[i].testval == 0 || arr[i].testval == 1) cnt++;
			for (int j = 0; j < n; j++) arr[j].testval = arr[j].val;
		}
		pw.println(cnt);
		pw.close();
	}
}
