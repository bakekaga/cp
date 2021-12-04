import java.util.*;
import java.io.*;

public class gymnastics {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("gymnastics.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("gymnastics.out"));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int k = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
		int[][] arr = new int[k][n];
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int a = 0, b = 0;
				for (int[] x : arr) {
					for (int cur : x) {
						if (cur == i) {
							a++;
							break;
						}
						if (cur == j) {
							b++;
							break;
						}
						
					}
				}
				if (a == 0 || b == 0) cnt++; 
			}
		}
		
		pw.println(cnt);
		pw.close();
	}
}
