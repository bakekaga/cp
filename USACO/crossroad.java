import java.util.*;
import java.io.*;
/*
ID: bakekaga
LANG: JAVA
TASK: crossroad
*/

public class crossroad {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("crossroad.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("crossroad.out")));
		int n = in.nextInt(), crossings = 0;
		HashMap<Integer, Integer> cows = new HashMap<>();
		int[][] arr = new int[n][2];
		for (int i = 0; i < n; i++) {
			arr[i][0] = in.nextInt();
			arr[i][1] = in.nextInt();
			if (!cows.containsKey(arr[i][0])) {
				cows.put(arr[i][0], arr[i][1]);
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i][1]!=cows.get(arr[i][0])) {
				crossings++;
				cows.remove(arr[i][0]);
				cows.put(arr[i][0], arr[i][1]);
			}
		}
		pw.print(crossings);
		pw.close();
	}
}