/*
ID: bakekaga
LANG: JAVA
TASK: Block Game
*/
import java.util.*;
import java.io.*;
public class blocks {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("blocks.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
		int n = in.nextInt();
		String[][] blocks = new String[n][2];
		
		int[] out = new int[26];
		for (int i = 0; i < n; i++) {
			blocks[i][0] = in.next();
			blocks[i][1] = in.next();
		}
		
		for (int i = 0; i < n; i++) {
			int[] word1 = new int[26];
			int[] word2 = new int[26];
			
			for (int j = 0; j < blocks[i][0].length(); j++) {
				word1[blocks[i][0].charAt(j)-'a']++;
			}
			for (int j = 0; j < blocks[i][1].length(); j++) {
				word2[blocks[i][1].charAt(j)-'a']++;
			}
			
			for (int j = 0; j < 26; j++) {
				out[j] += Math.max(word1[j], word2[j]);
			}
		}
		
		for (int i = 0; i < 26; i++) {
			pw.println(out[i]);
		}
		
		pw.close();
	}
}