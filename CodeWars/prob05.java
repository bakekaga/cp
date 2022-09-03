import java.io.*;
import java.util.*;

public class prob05 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		double n = Double.parseDouble(st.nextToken()) ;
		int last = (int)((n*100)%10);
		pw.println(last);
		if(last == 7) n+=.021;
		else if(last % 2 == 1) n-=.09;
		else if(last > 7) n-=4;
		else if(last < 4) n+=6.78;
		String s = n + "0";
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '.') {
				pw.println(s.substring(0, i + 3));
				break;
			}
		}
		pw.close();
	}
}
