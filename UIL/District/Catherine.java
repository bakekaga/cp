import java.io.*;
import java.util.*;

public class Catherine {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("catherine.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			String cor = st.nextToken();
			String g = st.nextToken();
			for(int j = 0; j < g.length(); j++){
				String sub = g.substring(j, j+1);
				if(cor.indexOf(sub) == j)
					System.out.print(sub.toUpperCase());
				else if(cor.indexOf(sub) >= 0)
					System.out.print(sub);
				else
					System.out.print("*");
			}
			System.out.println();
		}
		pw.close();
	}
}