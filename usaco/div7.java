import java.util.*;
import java.io.*;

/*
ID: bakekaga
LANG: JAVA
TASK: div7
*/

public class div7 {

	 
    static void shuffle(int[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            int temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static void shuffle(long[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            long temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    

	public static void main(String[] args) throws FileNotFoundException, IOException {
		FastReader in = new FastReader("div7.in");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("div7.out")));
//		PrintWriter pw = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int[] prefix = new int[n];
		prefix[0] = in.nextInt();
		int max = 0;
		
		int[] first = new int[7];
		int[] last = new int[7];
		
		first[prefix[0]] = 0;
		if (prefix[0] == 0) max = 1;
		
		for (int i = 1; i < n; i++) {
			prefix[i] = (in.nextInt() + prefix[i-1]) % 7;
			if (first[prefix[i]] == 0 && prefix[i] != prefix[0]) {
				first[prefix[i]] = i;
				if (prefix[i] == 0) max = Math.max(1,max);
			}
			else {
				last[prefix[i]] = i;
				max = Math.max(last[prefix[i]] - first[prefix[i]], max);
			}
		}
		
		pw.print(max);
		pw.close();
	}
}