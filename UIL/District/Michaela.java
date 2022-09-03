import java.io.*;
import java.util.*;

public class Michaela {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("michaela.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int m = Integer.parseInt(st.nextToken());
		String[] arr = {"-.....",
		"-.....-",
		"-....-.",
		"-....--",
		"-...-..",
		"-...-.-",
		"-...--.",
		"-...---",
		"-..-...",
		"-..-..-",
		"-..-.-.",
		"-..-.--",
		"-..--..",
		"-..--.-",
		"-..---.",
		"-..----",
		"-.-....",
		"-.-...-",
		"-.-..-.",
		"-.-..--",
		"-.-.-..",
		"-.-.-.-",
		"-.-.--.",
		"-.-.---",
		"-.--...",
		"-.--..-",
		"-.--.-."};
		
		for (int i = 1; i <= m; i++) {
			pw.print("Message #" + i + ": ");
			String s = br.readLine().toUpperCase();
			for (int j = 0; j < s.length(); j++) {
				if (s.charAt(j) == ' ') pw.print(arr[0] + " ");
				else pw.print(arr[s.charAt(j) - 'A' + 1] + " ");
			}
			pw.println();
		}
		pw.close();
	}
}