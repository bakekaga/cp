import java.util.*;
import java.io.*;

/*
ID: bakekaga
LANG: JAVA
TASK: whereami
*/

public class whereami {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("whereami.in"));
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

	public static int hashCode(char[] a) {
		int res = 17;
		for (int i = 0; i < a.length; i++) {
			res = 37*res + a[i];
		}
		return res;
	}
	public static void main(String[] args) throws FileNotFoundException, IOException {
		InputReader in = new InputReader();
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));
//		Scanner in = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		int n = in.nextInt();
		String x = in.next();
		char[] seq = x.toCharArray();
		for (int i = 1; i <= seq.length; i++) {
			HashSet<Integer> subseq = new HashSet<>();
			boolean same = false;
			for (int j = 0; j < seq.length - i+1; j++) {
				int y = hashCode(x.substring(j,j+i).toCharArray());
				if (subseq.contains(y)) {
					same = true;
					break;
				}
				else subseq.add(y);
			}
			if (same == false) {
				pw.println(i);
				break;
			}
		}
		pw.close();
	}
}