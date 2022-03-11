import java.io.*;
import java.util.*;

public class sleepinginclass {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for (int tt = 0; tt < t; tt++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), sum = 0, ans = n - 1;
			ArrayList<Integer> arr = new ArrayList<Integer>();
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				int x = Integer.parseInt(st.nextToken());
				sum+= x;
				arr.add(x);
			}
			if (sum == 0) {
				pw.println(0);
				continue;
			}
			ArrayList<Integer> divs = new ArrayList<Integer>();
			for (int i = 1; i * i <= sum; i++) {
				if (sum % i == 0) {
					divs.add(i);
					divs.add(sum / i);
				}
			}
			for (int div : divs) {
				int part = 0, cnt = 0;
				for (int i = 0; i < n; i++) {
					part+= arr.get(i);
					cnt++;
					if (part > div) {
						cnt = n - 1;
						break;
					}
					else if (part == div) {
						part = 0;
						cnt--;
					}
				}
				ans = Math.min(ans, cnt);
			}
			pw.println(ans);
		}
		pw.close();
	}
}
