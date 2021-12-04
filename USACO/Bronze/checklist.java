import java.util.*;
import java.io.*;

public class checklist {

    static long dist(int x1, int y1, int x2, int y2) {
    	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("checklist.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("checklist.out"));
        
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		long minDist[][][] = new long[n + 1][m + 1][2];
		long inf = 1L<<62;
		
		int[][] h = new int[n + 1][2];
		int[][] g = new int[m + 1][2];
		
		for (int i = 1; i < h.length; i++) {
            st = new StringTokenizer(br.readLine());
			h[i][0] = Integer.parseInt(st.nextToken());
			h[i][1] = Integer.parseInt(st.nextToken());
			if (i > 1) {
				minDist[i][0][0] = minDist[i - 1][0][0] + dist(h[i - 1][0], h[i - 1][1], h[i][0], h[i][1]);
				minDist[i][0][1] = inf;
			}
		}
		
		for (int i = 1; i < g.length; i++) {
			st = new StringTokenizer(br.readLine());
			g[i][0] = Integer.parseInt(st.nextToken());
			g[i][1] = Integer.parseInt(st.nextToken());
			minDist[0][i][0] = inf;
			minDist[0][i][1] = inf;
		}
						
		minDist[1][1][1] = dist(h[1][0], h[1][1], g[1][0], g[1][1]);
		minDist[1][1][0] = inf;
		
		for (int i = 2; i < minDist[1].length; i++) {
			minDist[1][i][1] = minDist[1][i - 1][1] + dist(g[i - 1][0], g[i - 1][1], g[i][0], g[i][1]);
			minDist[1][i][0] = inf;
		}
		
		for (int i = 2; i < minDist.length; i++) {
			for (int j = 1; j < minDist[i].length; j++) {
				minDist[i][j][0] = Math.min(minDist[i - 1][j][0] + dist(h[i - 1][0], h[i - 1][1], h[i][0], h[i][1]),
                 minDist[i - 1][j][1] + dist(g[j][0], g[j][1], h[i][0], h[i][1]));
				minDist[i][j][1] = Math.min(minDist[i][j - 1][0] + dist(h[i][0], h[i][1], g[j][0], g[j][1]),
                 minDist[i][j - 1][1] + dist(g[j - 1][0], g[j - 1][1], g[j][0], g[j][1]));
			}
		}
				
		pw.print(minDist[n][m][0]);
		pw.close();
	}
}