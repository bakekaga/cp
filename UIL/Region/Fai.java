import java.io.*;
import java.util.*;

public class Fai {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("dryrun.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		int t = Integer.parseInt(br.readLine());
		for (int tt = 0; tt < t; tt++) {
			String[] cities = br.readLine().split(",");
			
		}
		pw.close();
	}
}