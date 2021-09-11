import java.io.*;
import java.util.*;

public class notlast {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("notlast.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		String temp = "", ans = "";
		int min = 100 * n, min2 = 100 * n, tempint = 0;
		String[] log = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
		TreeMap<String, Integer> names = new TreeMap<>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			temp = st.nextToken();
			tempint = Integer.parseInt(st.nextToken());
			if (names.containsKey(temp)) names.replace(temp, tempint + names.get(temp));
			else names.put(temp, tempint);
		}
		
		for (int i = 0; i < 7; i++) {
			if (!names.containsKey(log[i])) {
				min = 0;
				names.put(log[i], 0);
			}
			min = Math.min(names.get(log[i]), min);
		}		
		for (int i = 0; i < 7; i++) {
			if (names.get(log[i]) > min) {
				if (names.get(log[i]) == min2) {
					pw.println("Tie");
					pw.close();
				}
				if (names.get(log[i]) < min2) {
					ans = log[i];
					min2 = names.get(log[i]);
				}
			}
		}
		if (ans.equals("")) pw.println("Tie");
		else pw.println(ans);
		pw.close();
	}
}