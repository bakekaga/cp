import java.io.*;
import java.util.*;

public class Arusha {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("arusha.dat"));
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int T = Integer.parseInt(st.nextToken());
		while(T > 0){
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			String m = st.nextToken();
			for(int i = 0; i < m.length(); i++){
				if(m.charAt(i) == 'L'){
					s = s.substring(1) + s.substring(0,1);
				}
				if(m.charAt(i) == 'R'){
					s = s.substring(s.length()-1) + s.substring(0, s.length()-1);
				}
			}
			pw.println(s);
			T--;

		}
		pw.close();
	}
}