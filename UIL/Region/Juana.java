import java.io.*;
import java.util.*;

public class Juana {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("juana.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());
		for (int tt = 1; tt <= t; tt++) {
			pw.print("Test case #" + tt + ":");
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
			int[][] arr = new int[n][m];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < m; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken()) - 1, c = Integer.parseInt(st.nextToken()) - 1, xl = Integer.parseInt(st.nextToken()), yl = Integer.parseInt(st.nextToken());
			if (r + yl - 1 >= n || c + xl - 1 >= m) {
				pw.println(" Unable to extract requested size!");
				for (int i = 0; i < 20; i++) pw.print("-");
				pw.println();
			}
			else {
				pw.println();
				for (int i = r; i < r + yl; i++) {
					for (int j = c; j < c + xl; j++) {
						String x = arr[i][j] + "";
						for (int k = 0; k < 5 - x.length(); k++) pw.print(" ");
						pw.print(x);
					}
					pw.println();
				}
				for (int i = 0; i < 20; i++) pw.print("-");
				pw.println();
			}
		}
		pw.close();
	}
}