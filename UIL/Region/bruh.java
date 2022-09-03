import java.io.*;
import java.util.*;

public class bruh {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("dryrun.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		pw.println(~Byte.MAX_VALUE);
		pw.close();
	}
}