import java.util.*;
import java.io.*;

public class countcross {

	static class Node {
		private int x, y;
		private LinkedList<Node> edges = new LinkedList<Node>();
		
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void dfs(Node n, boolean[][] visited) {
		int count = 0;
		for (Node each : n.edges) {
			if (visited[each.x][each.y] == true) {
				count++;
			}
			else {
				visited[each.x][each.y] = true;
				dfs(each, visited);
			}
			if (count == n.edges.size()) return;
		}
	}
    
	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("countcross.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("countcross.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		
		boolean[][][] visited = new boolean[k][n + 1][n + 1];
		Node[][] graph = new Node[n + 1][n + 1];
		Node[] cows = new Node[k];
	    int pairs = 0;

		for (int i = 1; i < graph.length; i++) {
			for (int j = 1; j < graph[i].length; j++) {
				graph[i][j] = new Node(i, j);
				
				if (i > 1) {
					graph[i][j].edges.add(graph[i - 1][j]);
					graph[i - 1][j].edges.add(graph[i][j]);	
				}
				if (j > 1) {
					graph[i][j].edges.add(graph[i][j - 1]);
					graph[i][j - 1].edges.add(graph[i][j]);
				}
			}
		}
		
		for (int i = 0; i < r; i++) {
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			graph[x1][y1].edges.remove(graph[x2][y2]);
			graph[x2][y2].edges.remove(graph[x1][y1]);
		}
		
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			cows[i] = graph[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())];
			dfs(cows[i], visited[i]);
			for (int j = 0; j < i; j++) {
				if (visited[j][cows[i].x][cows[i].y] == false) pairs++;
			}
		}
		
		pw.println(pairs);
		pw.close();
	}
}