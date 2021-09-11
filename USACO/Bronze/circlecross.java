import java.util.*;
import java.io.*;

public class circlecross {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("circlecross.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("circlecross.out")));
		
		String road = br.readLine();
		int count = 0;
		int[][] arr = new int[26][2];
		for (int i = 'A'; i <= 'Z'; i++) {
			arr[i-'A'][0] = road.indexOf(i);
			arr[i-'A'][1] = road.substring(arr[i - 'A'][0] + 1).indexOf(i) + arr[i - 'A'][0] + 1;
		}
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1] && arr[j][0] < arr[i][1]) count++;
			}
		}
		pw.println(count);
		pw.close();
	}
}