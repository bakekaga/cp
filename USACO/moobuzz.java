import java.util.*;
import java.io.*;

/*
ID: bakekaga
LANG: JAVA
TASK: moobuzz
*/

public class moobuzz {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("moobuzz.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("moobuzz.out")));
//		Scanner in = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		
		long n = in.nextLong();
		
		if (n % 8 == 1) pw.println(1 + n/8 * 15);
		else if (n % 8 == 2) pw.println(2 + n/8 * 15);
		else if (n % 8 == 3) pw.println(4 + n/8 * 15);
		else if (n % 8 == 4) pw.println(7 + n/8 * 15);
		else if (n % 8 == 5) pw.println(8 + n/8 * 15);
		else if (n % 8 == 6) pw.println(11 + n/8 * 15);
		else if (n % 8 == 7) pw.println(13 + n/8 * 15);
		else if (n % 8 == 0) pw.println(14 + (n-8)/8 * 15);
		
		pw.close();
	}
}