import java.io.*;
import java.util.*;

public class prob06 {	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int p = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		double r = Double.parseDouble(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		double i = p*r*t;

		String s = i + "0";
	    for(int j = s.length()-1; j >=0; j--){
			if(s.charAt(j) == '.'){
				pw.println(s.substring(0, j + 3));
				break;
			}
		}
		pw.close();
	}
}
