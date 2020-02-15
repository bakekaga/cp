import java.util.*;
import java.io.*;

/*
ID: bakekaga
LANG: JAVA
TASK: checklist
*/

public class checklist {

	 
    static void shuffle(int[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            int temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static void shuffle(long[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            long temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    
    public static long dist(int x1, int y1, int x2, int y2) {
    	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }

	public static void main(String[] args) throws FileNotFoundException, IOException {
		FastReader in = new FastReader("checklist.in");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("checklist.out")));
//		PrintWriter pw = new PrintWriter(System.out);
		
		int n = in.nextInt(), m = in.nextInt();
		
		long minDist[][][] = new long[n+1][m+1][2];
		long inf = 1L << 62;
		
		int[][] h = new int[n+1][2];
		int[][] g = new int[m+1][2];
		
		for (int i = 1; i < h.length; i++) {
			h[i][0] = in.nextInt();
			h[i][1] = in.nextInt();
			if (i > 1) {
				minDist[i][0][0] = minDist[i-1][0][0] + dist(h[i-1][0], h[i-1][1], h[i][0],h[i][1]);
				minDist[i][0][1] = inf;
			}
		}
		
		for (int i = 1; i < g.length; i++) {
			g[i][0] = in.nextInt();
			g[i][1] = in.nextInt();
			minDist[0][i][0] = inf;
			minDist[0][i][1] = inf;
		}
						
		minDist[1][1][1] = dist(h[1][0], h[1][1], g[1][0], g[1][1]);
		minDist[1][1][0] = inf;
		
		for (int i = 2; i < minDist[1].length; i++) {
			minDist[1][i][1] = minDist[1][i-1][1] + dist(g[i-1][0], g[i-1][1], g[i][0], g[i][1]);
			minDist[1][i][0] = inf;
		}
		
		for (int i = 2; i < minDist.length; i++) {
			for (int j = 1; j < minDist[i].length; j++) {
				minDist[i][j][0] = Math.min(minDist[i-1][j][0] + dist(h[i-1][0], h[i-1][1], h[i][0], h[i][1]), minDist[i-1][j][1] + dist(g[j][0], g[j][1], h[i][0], h[i][1]));
				minDist[i][j][1] = Math.min(minDist[i][j-1][0] + dist(h[i][0], h[i][1], g[j][0], g[j][1]), minDist[i][j-1][1] + dist(g[j-1][0], g[j-1][1], g[j][0], g[j][1]));
			}
		}
				
		pw.print(minDist[n][m][0]);
		pw.close();
	}
}