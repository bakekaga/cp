import java.io.*;
import java.util.*;

public class prob08 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int count = 0;
		int min = 0;
		while(n > 0){
			st = new StringTokenizer(br.readLine());
			String[] arr = st.nextToken().split(":");
			count += Integer.parseInt(arr[1]);
			min += Integer.parseInt(arr[0]);
			n--;
		}
		int r = count % 60;
		min += count / 60;
		if(r < 10)
			pw.println(min + ":0" + r);
		else 
		pw.println(min + ":" + r);

		pw.close();
	}
}
