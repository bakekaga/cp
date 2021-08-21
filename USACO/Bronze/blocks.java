import java.util.*;
import java.io.*;

public class blocks {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader(new FileReader("blocks.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		String[][] blocks = new String[n][2];
		
		int[] out = new int[26];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(in.readLine());
			blocks[i][0] = st.nextToken();
			blocks[i][1] = st.nextToken();
		}
		
		for (int i = 0; i < n; i++) {
			int[] word1 = new int[26];
			int[] word2 = new int[26];
			
			for (int j = 0; j < blocks[i][0].length(); j++) {
				word1[blocks[i][0].charAt(j) - 'a']++;
			}
			for (int j = 0; j < blocks[i][1].length(); j++) {
				word2[blocks[i][1].charAt(j) - 'a']++;
			}
			
			for (int j = 0; j < 26; j++) {
				out[j] += Math.max(word1[j], word2[j]);
			}
		}
		
		for (int i = 0; i < 26; i++) {
			pw.println(out[i]);
		}
		
		pw.close();
	}
}