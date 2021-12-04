import java.util.*;
import java.io.*;

public class gymnastics {

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
		BufferedReader br = new BufferedReader(new FileReader("gymnastics.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("gymnastics.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int k = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
		TreeSet<Pair> start = new TreeSet<>();
		int[][] matrix = new int[k][n];
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				matrix[i][j] = Integer.parseInt(st.nextToken());
			}
			if (i == 0) {
				for (int j = 0; j < n; j++) {
					for (int l = j + 1; l < n; l++) {
						start.add(new Pair(matrix[0][j], matrix[0][l]));
					}
				}
			}
			else {
				TreeSet<Pair> notstart = new TreeSet<>();
				for (int j = 0; j < n; j++) {
					for (int l = j + 1; l < n; l++) {
						notstart.add(new Pair(matrix[i][j], matrix[i][l]));
					}
				}
				start.retainAll(notstart);
			}
		}
		pw.print(start.size());
		pw.close();
	}
}