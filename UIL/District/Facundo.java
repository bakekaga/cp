import java.io.*;
import java.util.*;

public class Facundo {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("facundo.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		while( n> 0){
			st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			int t = Integer.parseInt(st.nextToken());
			String r = s;
			while(t > 0){
				String one = "";
				String two = "";
				if(r.length() % 2 == 1){
					one = r.substring(0, r.length()/2 +1);
					two = r.substring(r.length()/2 +1);
				}else{
					one = r.substring(0, r.length()/2);
					two = r.substring(r.length()/2);
				}
				r = "";
				for(int i = 0; i < two.length(); i++){
					if(s.length()%2==1){
					r += one.substring(i, i+1);
					r += two.substring(i, i+1);
					}else{
						
					r += two.substring(i, i+1);
					r += one.substring(i, i+1);
					}

				}
				if(s.length() % 2 ==1){
					r += one.substring(one.length()-1);
				}
				t--;
			}
			n--;
			pw.println(r);
		}
		pw.close();
	}
}