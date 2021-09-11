import java.io.*;
import java.util.*;

public class paint {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("paint.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
		
		pw.println(b - a + d - c - ((Math.max(a, c) < Math.min(b, d)) ? (Math.min(b, d) - Math.max(a, c)) : 0));
		pw.close();
	}
}