import java.util.*;
import java.io.*;

public class div7 {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("div7.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("div7.out"));
        
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), max = 0;
		int[] first = new int[7];
		int[] last = new int[7];
        int[] prefix = new int[n];
        st = new StringTokenizer(br.readLine());
		prefix[0] = Integer.parseInt(st.nextToken());
		
		first[prefix[0]] = 0;
		if (prefix[0] == 0) max = 1;
		
		for (int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
			prefix[i] = (Integer.parseInt(st.nextToken()) + prefix[i - 1]) % 7;
			if (first[prefix[i]] == 0 && prefix[i] != prefix[0]) {
				first[prefix[i]] = i;
				if (prefix[i] == 0) max = Math.max(1, max);
			}
			else {
				last[prefix[i]] = i;
				max = Math.max(last[prefix[i]] - first[prefix[i]], max);
			}
		}
		
		pw.println(max);
		pw.close();
	}
}