import java.util.*;
import java.io.*;

public class triangles {

    static class Fence {
        // heightsum is the sum of the heights of all the triangles
        // that use this fence as an anchor point, basesum is the
        // sum of the bases of all the triangles that use this
        // fence as an anchor point; recall that the anchor point
        // of a right triangle is the vertex where the right
        // angle is.
        int x, y;
        long heightsum, basesum;
    }

    static class Pair implements Comparable<Pair> {
        int first, second;

        public Pair(int x, int y) {
            first = x;
            second = y;
        }

        public int compareTo(Pair x) {
            if (this.first == x.first) return this.second - x.second;
            return this.first - x.first;
        }
    }
    
	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader(new FileReader("triangles.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("triangles.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
        int n = Integer.parseInt(st.nextToken());
        int MOD = 1000000007;

        // fences are our fences, xcoords represents all of the possible
        // x coordinates of our fences, ycoords represents all of the
        // possible y coordinates of our fences
        Fence[] fences = new Fence[n];
        ArrayList<Pair>[] xcoords = new ArrayList[20001];
        ArrayList<Pair>[] ycoords = new ArrayList[20001];

        for (int i = 0; i < n; i++) {
        	st = new StringTokenizer(in.readLine());
        	fences[i] = new Fence();
            fences[i].x = Integer.parseInt(st.nextToken());
            fences[i].y = Integer.parseInt(st.nextToken());
            // we add 100000 to make all of our coordinates positive
            // so that we won't have negative indices
            if (xcoords[fences[i].x + 10000] == null) xcoords[fences[i].x + 10000] = new ArrayList<Pair>();
            if (ycoords[fences[i].y + 10000] == null) ycoords[fences[i].y + 10000] = new ArrayList<Pair>();
            xcoords[fences[i].x + 10000].add(new Pair(fences[i].y, i));
            ycoords[fences[i].y + 10000].add(new Pair(fences[i].x, i));
        }

        for (int i = 0; i <= 20000; i++) {
            if (xcoords[i] != null) {
                // cur is the value of the current s_i
                long cur = 0;
                // first we sort all of the y coordinates of each set
                // of points with the same x coordinate
                Collections.sort(xcoords[i]);
                // then we compute the value s_1 of this set:
                // the sum of the heights of all the triangles that
                // have anchor point at (i, xcoords[i][0].first)
                for (int j = 1; j < xcoords[i].size(); j++) {
                    cur+= xcoords[i].get(j).first - xcoords[i].get(0).first;
                }
                fences[xcoords[i].get(0).second].heightsum = cur;
                // then we compute the rest of the s_i for this set
                for (int j = 1; j < xcoords[i].size(); j++) {
                    cur+= (2 * j - xcoords[i].size()) * (xcoords[i].get(j).first - xcoords[i].get(j - 1).first);
                    fences[xcoords[i].get(j).second].heightsum = cur;
                }
            }
        }

        // we do the sums of bases in exactly the same way
        for (int i = 0; i <= 20000; i++) {
            if (ycoords[i] != null) {
                long cur = 0;
                Collections.sort(ycoords[i]);
                for (int j = 1; j < ycoords[i].size(); j++) {
                    cur+= ycoords[i].get(j).first - ycoords[i].get(0).first;
                }
                fences[ycoords[i].get(0).second].basesum = cur;
                for (int j = 1; j < ycoords[i].size(); j++) {
                    cur+= (2 * j - ycoords[i].size()) * (ycoords[i].get(j).first - ycoords[i].get(j - 1).first);
                    fences[ycoords[i].get(j).second].basesum = cur;
                }
            }
        }

        // finally we compute the total area
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret+= fences[i].heightsum * fences[i].basesum % MOD;
            ret%= MOD;
        }
        pw.println(ret);
        pw.close();
    }
}
