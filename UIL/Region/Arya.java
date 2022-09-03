import java.io.*;
import java.util.*;

public class Arya {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("arya.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			int min = 1;
			int max = Integer.parseInt(st.nextToken());
			int target = Integer.parseInt(st.nextToken());
			while(max >= min){
				int mid = (max + min) / 2;
				if(mid == target){
					pw.println(min + "-" + mid + "-" + max);
					pw.println("GOT IT!!!");
					break;
				}
				else if(mid > target){
					pw.println(min + "-" + mid + "-" + max);
					max = mid - 1;
				}
				else{
					pw.println(min + "-" + mid + "-" + max);
					min = mid + 1;
				}
			}
		}
	
		pw.close();
	}
}