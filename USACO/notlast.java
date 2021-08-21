/*
ID: bakekaga
LANG: JAVA
TASK: Don't Be Last!
*/
import java.io.*;
import java.util.*;

public class notlast {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("notlast.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));
		int n = in.nextInt();
		String temp = "", ans = "";
		int min = 100*n, min2 = 100*n, tempint = 0;
		String[] log = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
		HashMap<String, Integer> names = new HashMap<>();
		for (int i = 0; i < n; i++) {
			temp = in.next();
			tempint = in.nextInt();
			if (names.containsKey(temp)) names.replace(temp,tempint+names.get(temp));
			else names.put(temp, tempint);
		}
		
		for (int i = 0; i < 7; i++) {
			if (!names.containsKey(log[i])) {
				min = 0;
				names.put(log[i],0);
			}
			min = Math.min(names.get(log[i]), min);
		}		
		for (int i = 0; i < 7; i++) {
			if (names.get(log[i]) > min) {
				if (names.get(log[i]) == min2) {
					pw.println("Tie");
					pw.close();
				}
				if (names.get(log[i]) < min2) {
					ans = log[i];
					min2 = names.get(log[i]);
				}
			}
		}
		if (ans.equals("")) pw.print("Tie");
		pw.println(ans);
		pw.close();
	}
}