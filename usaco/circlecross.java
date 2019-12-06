import java.util.*;
import java.io.*;
/*
ID: bakekaga
LANG: JAVA
TASK: circlecross
*/
public class circlecross {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("circlecross.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("circlecross.out")));
		String road = in.next(); int count = 0; int[][] arr = new int[26][2];
		for (int i = 'A'; i <= 'Z'; i++) {
			arr[i-'A'][0] = road.indexOf(i);
			arr[i-'A'][1] = road.substring(arr[i-'A'][0]+1).indexOf(i)+arr[i-'A'][0]+1;
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1] && arr[j][0] < arr[i][1]) count++;
			}
		}
		pw.print(count);
		pw.close();
	}
}