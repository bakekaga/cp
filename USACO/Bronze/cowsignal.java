import java.util. * ;
import java.io. * ;

public class cowsignal {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("cowsignal.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("cowsignal.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		char[][] input = new char[m][n];
		for (int i = 0; i < m; i++) {
			input[i] = br.readLine().toCharArray();
		}
		
		char[][] output = new char[m * k][n * k];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int l = 0; l < k; l++) {
					output[i * k][j * k + l] = input[i][j];
				}
			}
			for (int j = i * k + 1; j < (i + 1) * k; j++) {
				output[j] = output[i * k];
			}
		}
		for (int i = 0; i < output.length; i++) {
			for (int j = 0; j < output[i].length; j++) {
				pw.print(output[i][j]);
			}
			pw.println();
		}
		pw.close();
	}
}