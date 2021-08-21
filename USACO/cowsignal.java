/*
ID: bakekaga
LANG: JAVA
TASK: The Cow-Signal
*/
import java.util.*;
import java.io.*;
public class cowsignal {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("cowsignal.in"));
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
		int m = in.nextInt(), n = in.nextInt(), k = in.nextInt();
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cowsignal.out")));
		char[][] input = new char[m][n];
		for (int i = 0; i < m; i++) {
				input[i] = in.next().toCharArray();
		}
		
		char[][] output = new char[m*k][n*k];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < k; l++) {
					output[i*k][j*k+l] = input[i][j];
				}
			}
			for (int j = i*k+1; j < (i+1)*k; j++) {
				output[j] = output[i*k];
			}
		}
		for (int i = 0; i < output.length; i++) {
			for (int j = 0; j < output[i].length; j++) {
				pw.print(output[i][j]);
			}
			pw.println();
		}
		pw.close();
	}
}