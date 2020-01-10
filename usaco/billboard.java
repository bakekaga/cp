import java.util.*;
import java.io.*;
/*
ID: bakekaga
LANG: JAVA
TASK: billboard
*/
public class billboard {

	static class InputReader {
		BufferedReader reader;
		StringTokenizer tokenizer;
		public InputReader() throws FileNotFoundException {
			reader = new BufferedReader(new FileReader("billboard.in"));
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
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
//		Scanner in = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
		int[][] board1 = {{x1,y1},{x2,y2}};
		x1 = in.nextInt();
		y1 = in.nextInt();
		x2 = in.nextInt();
		y2 = in.nextInt();
		int[][] board2 = {{x1,y1},{x2,y2}};
		x1 = in.nextInt();
		y1 = in.nextInt();
		x2 = in.nextInt();
		y2 = in.nextInt();
		int[][] truck = {{x1,y1},{x2,y2}};
		int truckx1 = 0, truckx2 = 0, trucky1 = 0, trucky2 = 0;
		
		// determine truckx1
		if (truck[0][0] > board1[0][0] && truck[0][0] < board1[1][0]) {
			if (truck[1][0] > board1[0][0] && truck[1][0] < board1[1][0]) truckx1 = truck[1][0] - truck[0][0];
			else truckx1 = board1[1][0] - truck[0][0];
		}
		else if (truck[0][0] < board1[0][0] && truck[1][0] > board1[1][0]) {
			truckx1 = board1[1][0] - board1[0][0];
		}
		else if (truck[1][0] > board1[0][0] && truck[1][0] < board1[1][0]) {
			if (truck[0][0] > board1[0][0] && truck[0][0] < board1[1][0]) truckx1 = truck[1][0] - truck[0][0];
			else truckx1 = truck[1][0] - board1[0][0];
		}
		
		// determine trucky1
		if (truck[0][1] > board1[0][1] && truck[0][1] < board1[1][1]) {
			if (truck[1][1] > board1[0][1] && truck[1][1] < board1[1][1]) trucky1 = truck[1][1] - truck[0][1];
			else trucky1 = board1[1][1] - truck[0][1];
		}
		else if (truck[0][1] < board1[0][1] && truck[1][1] > board1[1][1]) {
			trucky1 = board1[1][1] - board1[0][1];
		}
		else if (truck[1][1] > board1[0][1] && truck[1][1] < board1[1][1]) {
			if (truck[0][1] > board1[0][1] && truck[0][1] < board1[1][1]) trucky1 = truck[1][1] - truck[0][1];
			else trucky1 = truck[1][1] - board1[0][1];
		}
		
		// determine truckx2
		if (truck[0][0] > board2[0][0] && truck[0][0] < board2[1][0]) {
			if (truck[1][0] > board2[0][0] && truck[1][0] < board2[1][0]) truckx2 = truck[1][0] - truck[0][0];
			else truckx2 = board2[1][0] - truck[0][0];
		}
		else if (truck[0][0] < board2[0][0] && truck[1][0] > board2[1][0]) {
			truckx2 = board2[1][0] - board2[0][0];
		}
		else if (truck[1][0] > board2[0][0] && truck[1][0] < board2[1][0]) {
			if (truck[0][0] > board2[0][0] && truck[0][0] < board2[1][0]) truckx2 = truck[1][0] - truck[0][0];
			else truckx2 = truck[1][0] - board2[0][0];
		}
		
		// determine trucky2
		if (truck[0][1] > board2[0][1] && truck[0][1] < board2[1][1]) {
			if (truck[1][1] > board2[0][1] && truck[1][1] < board2[1][1]) trucky2 = truck[1][1] - truck[0][1];
			else trucky2 = board2[1][1] - truck[0][1];
		}
		else if (truck[0][1] < board2[0][1] && truck[1][1] > board2[1][1]) {
			trucky2 = board2[1][1] - board2[0][1];
		}
		else if (truck[1][1] > board2[0][1] && truck[1][1] < board2[1][1]) {
			if (truck[0][1] > board2[0][1] && truck[0][1] < board2[1][1]) trucky2 = truck[1][1] - truck[0][1];
			else trucky2 = truck[1][1] - board2[0][1];
		}

//		pw.println(truckx1);
//		pw.println(trucky1);
//		pw.println(truckx2);
//		pw.println(trucky2);
		int out = Math.abs(board1[0][1]-board1[1][1])*Math.abs(board1[0][0]-board1[1][0]) + Math.abs(board2[0][1]-board2[1][1])*Math.abs(board2[0][0]-board2[1][0]) - Math.abs(truckx1 * trucky1) - Math.abs(truckx2 * trucky2);
		pw.print(out);
		pw.close();
	}
}