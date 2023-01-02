import java.util.*;
import java.io.*;

public class photoshoot2 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		int[] a = new int[n], b = new int[n + 1];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) a[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++) {
			int x = Integer.parseInt(st.nextToken());
			b[x] = i;
		}

		int maxPos = -1, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (b[a[i]] < maxPos) cnt++;
			else maxPos = b[a[i]];
		}
		pw.println(cnt);
		pw.close();
	}
}