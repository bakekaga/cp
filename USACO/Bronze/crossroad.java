import java.util.*;
import java.io.*;

public class crossroad {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("crossroad.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("crossroad.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), crossings = 0;
		TreeMap<Integer, Integer> cows = new TreeMap<>();
		int[][] arr = new int[n][2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
			if (!cows.containsKey(arr[i][0])) {
				cows.put(arr[i][0], arr[i][1]);
			}
		}

		for (int i = 0; i < n; i++) {
			if (arr[i][1] != cows.get(arr[i][0])) {
				crossings++;
				cows.remove(arr[i][0]);
				cows.put(arr[i][0], arr[i][1]);
			}
		}
		pw.println(crossings);
		pw.close();
	}
}