import java.util.*;
import java.io.*;

public class whereami {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("whereami.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		String x = br.readLine();
		char[] seq = x.toCharArray();
		
		for (int i = 1; i <= seq.length; i++) {
			TreeSet<char[]> subseq = new TreeSet<>();
			boolean same = false;
			for (int j = 0; j < seq.length - i + 1; j++) {
				char[] y = x.substring(j, j + i).toCharArray();
				if (subseq.contains(y)) {
					same = true;
					break;
				}
				else subseq.add(y);
			}
			if (same == false) {
				pw.println(i);
				break;
			}
		}
		pw.close();
	}
}