import java.io.*;
import java.util.*;

public class robotinstructions {

	static int val;
	static int[] dest;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		dest = new int[2];
		st = new StringTokenizer(br.readLine());
		dest[0] = Integer.parseInt(st.nextToken());
		dest[1] = Integer.parseInt(st.nextToken());
		int[][] instructions = new int[n][2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			instructions[i][0] = Integer.parseInt(st.nextToken());
			instructions[i][1] = Integer.parseInt(st.nextToken());
		}

		for (int k = 1; k <= n; k++) {
			val = 0;
			combinations2(instructions, k, 0, new int[k][2]);
			pw.println(val);
		}
		pw.close();
	}
	
    static void combinations2(int[][] arr, int len, int startPosition, int[][] result){
        if (len == 0){
			int sumx = 0, sumy = 0;
			for (int i = 0; i < result.length; i++) {
				sumx+= result[i][0];
				sumy+= result[i][1];
			}
			if (sumx == dest[0] && sumy == dest[1]) val++;
            return;
        }
        for (int i = startPosition; i <= arr.length-len; i++){
            result[result.length - len] = arr[i];
            combinations2(arr, len-1, i+1, result);
        }
    }
}