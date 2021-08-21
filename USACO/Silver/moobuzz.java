import java.util.*;
import java.io.*;

public class moobuzz {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader(new FileReader("moobuzz.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("moobuzz.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		long n = Long.parseLong(st.nextToken());
		
		if (n % 8 == 1) pw.println(1 + n / 8 * 15);
		else if (n % 8 == 2) pw.println(2 + n / 8 * 15);
		else if (n % 8 == 3) pw.println(4 + n / 8 * 15);
		else if (n % 8 == 4) pw.println(7 + n / 8 * 15);
		else if (n % 8 == 5) pw.println(8 + n / 8 * 15);
		else if (n % 8 == 6) pw.println(11 + n / 8 * 15);
		else if (n % 8 == 7) pw.println(13 + n / 8 * 15);
		else if (n % 8 == 0) pw.println(14 + (n-8) / 8 * 15);
		
		pw.close();
	}
}