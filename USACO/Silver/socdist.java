import java.util.*;
import java.io.*;

public class socdist {
	
    static class Pair implements Comparable<Pair> {
        long first, second;

        public Pair(long x, long y) {
            first = x;
            second = y;
        }

        public int compareTo(Pair x) {
            if (this.first == x.first) return (int) (this.second - x.second);
            return (int) (this.first - x.first);
        }
    }
    
    // greedy algorithm
    static boolean ok(long d, int n, int m, Pair[] intervals) {
        int count = 1, intervalCount = 0;
        long current = intervals[0].first;
        while ((current + d) < intervals[m - 1].second) {
            while (current + d > intervals[intervalCount].second) {
                intervalCount++;
            }
            current = Math.max(intervals[intervalCount].first, current + d);
            count++;
            if (count == n) return true;
        }
        return count >= n;
    }

	public static void main(String[] args) throws FileNotFoundException, IOException {
        // BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(System.out);
		BufferedReader in = new BufferedReader(new FileReader("socdist.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("socdist.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        Pair intervals[] = new Pair[m];
        for (int i = 0; i < m; i++) {
        	st = new StringTokenizer(in.readLine());
        	intervals[i] = new Pair(Long.parseLong(st.nextToken()), Long.parseLong(st.nextToken()));
        }
        
        Arrays.sort(intervals);
        // binary search
        long x = 0;
        for (long b = 1000000000; b >= 1; b/= 2) {
            while (ok(x + b, n, m, intervals)) x += b;
        }
        pw.print(x);
        pw.close();
	}
}