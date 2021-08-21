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
    
	public static void main(String[] args) throws FileNotFoundException, IOException {
        // // BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
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
        long lo = 0, hi = intervals[m - 1].second - intervals[0].first + 1;
        while (lo < hi) {
            // greedy algorithm
            long mid = lo + (hi - lo + 1) / 2;
            int count = 1, intervalCount = 0;
            long current = intervals[0].first;
            while ((current + mid) < intervals[m - 1].second) {
                while (current + mid > intervals[intervalCount].second) {
                    intervalCount++;
                }
                current = Math.max(intervals[intervalCount].first, current + mid);
                count++;
                if (count == n) break;
            }
            if (count >= n) lo = mid;
            else hi = mid - 1;
        }
        pw.println(lo);
        pw.close();
	}
}