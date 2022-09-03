import java.io.*;
import java.util.*;

public class Michal {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("michal.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		String[][] arr0 = {{" "," "},{" ", " "}};
		//int n = Integer.parseInt(st.nextToken());
		pw.println(arr0[0][0]);
		pw.close();
	}
}