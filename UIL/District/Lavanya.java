import java.io.*;
import java.util.*;

public class Lavanya {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("lavanya.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		for (int t = 0; t < n; t++) {
			st = new StringTokenizer(br.readLine());
			int cur = Integer.parseInt(st.nextToken());
			String str = cur + " = ";
			for (int i = 2; cur > 1; i++) {
				while (cur % i == 0) {
					str+= i + " * ";
					cur/= i;
				}
			}
			pw.println(str.substring(0, str.length() - 3));
		}
		pw.close();
	}
}