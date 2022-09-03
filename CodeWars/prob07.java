import java.io.*;
import java.util.*;

public class prob07 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int n = 5;
		ArrayList<Integer> arr1 = new ArrayList<Integer>();
		Map<Integer, String> map = new TreeMap<Integer, String>();
		while(n > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] arr = new int[6];
			for(int i = 0; i < 6; i++){
				arr[i] = Integer.parseInt(st.nextToken());
			}
			String s = st.nextToken();
			int count = 0;
			for(int i = 1; i < 6; i+=2){
				int x = arr[i-1] - arr[i];
				if(x >= 0){
					count+= x;
				}
			}
			arr1.add(count);
			map.put(count, s);
			n--;
		}
		Collections.sort(arr1);
		for(int j = arr1.size() -1 ; j >= 0; j--){
			pw.println(map.get(arr1.get(j)) + " " + arr1.get(j));
		}
		
		pw.close();
	}
}
