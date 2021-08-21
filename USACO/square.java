/*
ID: bakekaga
LANG: JAVA
TASK: Square Pasture
*/
import java.util.*;
import java.io.*;
public class square {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("square.in"));
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

public static void main(String[] args) throws FileNotFoundException, IOException {
	InputReader in = new InputReader();
	PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("square.out")));
	int[] pasture1 = {in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt()};
	int[] pasture2 = {in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt()};
	int xmin = Math.min(Math.min(pasture1[0], pasture2[0]), Math.min(pasture1[2], pasture2[2]));
	int xmax = Math.max(Math.max(pasture1[0], pasture2[0]), Math.max(pasture1[2], pasture2[2]));
	int ymin = Math.min(Math.min(pasture1[1], pasture2[1]), Math.min(pasture1[3], pasture2[3]));
	int ymax = Math.max(Math.max(pasture1[1], pasture2[1]), Math.max(pasture1[3], pasture2[3]));
	pw.println(Math.max(ymax-ymin, xmax-xmin)*Math.max(ymax-ymin, xmax-xmin));
	pw.close();
	}
}