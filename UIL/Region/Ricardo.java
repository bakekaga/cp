import java.io.*;
import java.util.*;

public class Ricardo {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("ricardo.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());
		for (int tt = 0; tt < t; tt++) {
			String inp = br.readLine();
			String[] arr = inp.split(",");
			int count = 1;
			for(int i = 0; i < arr.length; i++){
				String str = arr[i];
				if(str.contains("|")){
					// pw.println(str.contains("|"));
					// String[] p = str.split("|");
					int p = 0;
					for(int j = 0; j < str.length(); j++){
						if(str.substring(i, i+1).equals("|")){
							p++;
						}
					}

					count *= p+1;
				}
			}
			// int x = 1;
			// for(int i = 0; i < count; i++){
			// 	x *= 2;
			// }
			pw.println("Case #" + (tt+1) + ": " + count);
		}
		pw.close();
	}
}