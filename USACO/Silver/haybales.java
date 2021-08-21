import java.util.*;
import java.io.*;

public class haybales {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader(new FileReader("haybales.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("haybales.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        
        int haybales[] = new int[n];
    	st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
        	haybales[i] = Integer.parseInt(st.nextToken());
        }
        
        Arrays.sort(haybales);
        for (int i = 0; i < q; i++) {
        	st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (haybales[mid] >= a) hi = mid;
                else lo = mid + 1;
            }
            int left = lo;
            
            lo = 0; hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (haybales[mid] > b) hi = mid;
                else lo = mid + 1;
            }
            int right = lo;
            
            pw.println(right - left);
        }
		pw.close();
	}
}