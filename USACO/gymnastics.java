import java.util.*;
import java.io.*;

/*
ID: bakekaga
LANG: JAVA
TASK: gymnastics
*/

public class gymnastics {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("gymnastics.in"));
			tokenizer = null;
		}

		String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public float nextFloat() {
			return Float.parseFloat(next());
		}

	}

	public static int hashAdd(int a, int b) {
		return 37 * (37 * 17 + a) + b;
	}
	
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		InputReader in = new InputReader();
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("gymnastics.out")));
//		Scanner in = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		int k = in.nextInt(), n = in.nextInt();
		HashSet<Integer> start = new HashSet<>();
		int[][] matrix = new int[k][n];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = in.nextInt();
			}
			if (i == 0) {
				for (int j = 0; j < n; j++) {
					for (int l = j+1; l < n; l++) {
						start.add(hashAdd(matrix[0][j], matrix[0][l]));
					}
				}
			}
			else {
				HashSet<Integer> notstart = new HashSet<>();
				for (int j = 0; j < n; j++) {
					for (int l = j+1; l < n; l++) {
						notstart.add(hashAdd(matrix[i][j], matrix[i][l]));
					}
				}
				start.retainAll(notstart);
			}
		}
		pw.print(start.size());
		pw.close();
	}
}