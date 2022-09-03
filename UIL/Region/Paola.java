import java.io.*;
import java.util.*;

public class Paola {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("paola.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int T = Integer.parseInt(st.nextToken());
		while(T > 0){
			st = new StringTokenizer(br.readLine());
			char Ch = st.nextToken().charAt(0);
			int N = Integer.parseInt(st.nextToken());
			int x = 1;
			while(x <= N){
				for(int i = 0; i < N - x; i++){
					pw.print(" ");
				}
				for(int i = 0; i < x; i++){
					pw.print(Ch);
					Ch++;
					if(Ch == '['){
						Ch = 'A';
					}
					
				}
				pw.println();
				x++;				
			}
			T--;
		}
		//pw.println(~Byte.MAX_VALUE);
		pw.close();
	}
}