import java.io.*;
import java.util.*;

public class Shivam {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("dryrun.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());
		for (int tt = 1; tt <= t; tt++) {
			String[] x = br.readLine().split("=");
			String a = (x[1].substring(0, x[1].indexOf("x^2"))), b = "", c = "";
			if (x[1].indexOf("x", x[1].indexOf("x^2") + 3) >= 0) {
				b = x[1].substring(x[1].indexOf("x^2") + 3, x[1].indexOf("x", x[1].indexOf("x^2") + 3));
				c = x[1].substring(x[1].indexOf("x", x[1].indexOf("x^2") + 3) + 1);
			}
			else {
				c = x[1].substring(x[1].indexOf("x^2") + 3);
			}
			int aVal = (!a.equals("") ? Integer.parseInt(a) : 1), bVal = (!b.equals("") ? Integer.parseInt(b) : 0), cVal = (!c.equals("") ? Integer.parseInt(c) : 0);
			int disc = bVal * bVal - 4 * aVal * cVal;
			if (disc < 0) pw.println("There are no real roots to the function.");
			else if (disc == 0) {
				// double lo = 0, hi = 
			} 
		}
		pw.close();
	}
}