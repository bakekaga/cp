import java.util.*;
import java.io.*;
/*
ID: bakekaga
LANG: JAVA
TASK: cowqueue
*/
public class cowqueue {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("cowqueue.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cowqueue.out")));
//		Scanner in = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		int n = in.nextInt(); ArrayList<Integer> entryTimes = new ArrayList<Integer>();
		if (n == 1) pw.print(in.nextInt() + in.nextInt());
		else {
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			for (int i = 0; i < n; i++) {
				int e = in.nextInt(), q = in.nextInt();
				map.put(e, q);
				entryTimes.add(e);
			}
			Collections.sort(entryTimes);
			int time = entryTimes.get(0);
				for (int i = 0; i < entryTimes.size()-1; i++) {
					time+= map.get(entryTimes.get(i));
					if (time <= entryTimes.get(i+1)) {
						time = entryTimes.get(i+1);	
					}
					if (i == entryTimes.size() - 2) time+= map.get(entryTimes.get(i+1));
				}
		pw.print(time);
		}
		pw.close();
	}
}