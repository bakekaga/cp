import java.io.*;
import java.util.*;

public class Diane {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("dryrun.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		while (n > 0) {
			String[] str = br.readLine().split(" ");
			if (str.length == 5) {
				
			}
			n--;
		}
		pw.close();
	}
}