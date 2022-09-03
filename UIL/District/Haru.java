import java.io.*;
import java.util.*;

public class Haru {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("haru.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int[][] grid;

		for(int i = 0; i < n; i++){
			grid = new int[103][103];
			for (int j = 0; j <= 100; j++) {
				grid[0][j]++;
				grid[j][0]++;
				grid[100][j]++;
				grid[j][100]++;
			}
			st = new StringTokenizer(br.readLine());
			int moves = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken()) + 1;
			int y1 = Integer.parseInt(st.nextToken()) + 1;
			String m1 = st.nextToken();
			st = new StringTokenizer(br.readLine());
			int x2 = Integer.parseInt(st.nextToken()) + 1;
			int y2 = Integer.parseInt(st.nextToken()) + 1;
			String m2 = st.nextToken();
			grid[x1][y1] = 1;
			grid[x2][y2] = 1;
			boolean ok = false;
			for(int j = 0; j < moves; j++){
				int prevx1 = x1, prevx2 = x2, prevy1 = y1, prevy2 = y2;
				if (m1.charAt(j) == 'R') x1++;
				else if (m1.charAt(j) == 'L') x1--;
				else if (m1.charAt(j) == 'U') y1++;
				else if (m1.charAt(j) == 'D') y1--;

				if (m2.charAt(j) == 'R') x2++;
				else if (m2.charAt(j) == 'L') x2--;
				else if (m2.charAt(j) == 'U') y2++;
				else if (m2.charAt(j) == 'D') y2--;
				if (prevx1 == x2 && prevy1 == y2 && prevx2 == x1 && prevy2 == y1 || (x1 == x2 && y1 == y2)) {
					pw.println("HEAD ON");
					ok = true;
					break;
				}
				else if (grid[x1][y1] > 0 && grid[x2][y2] > 0) {
					pw.println("DOUBLE SPIKE");
					ok = true;
					break;
				}
				else if (grid[x1][y1] > 0) {
					pw.println("P2 WIN");
					ok = true;
					break;
				}
				else if (grid[x2][y2] > 0) {
					pw.println("P1 WIN");
					ok = true;
					break;
				}
				
				grid[x1][y1] = 1;
				grid[x2][y2] = 1;
			}
			if (!ok) pw.println("DRAW");
		}
		pw.close();
	}
}