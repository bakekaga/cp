import java.io.*;
import java.util.*;

public class prob09 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		Map<String, Integer> set = new HashMap<String, Integer>();
		ArrayList<String> arr = new ArrayList<String>();
		int b = 0;
		int n = 0;
		while(st.hasMoreTokens()){
			n++;
			String s = st.nextToken();
			arr.add(s);
			if(set.containsKey(s)){
				set.put(s, set.get(s) + 1);
			}else{
			set.put(s,1);
				b = n;
			}

			if(b ==2 && arr.size() > 2){
				if(arr.get(1).equals(arr.get(2))){
					b = 1;
				}
			}
		}
		for(String str : set.keySet()){
			if(set.get(str) == 1){
				pw.println("#" + b + " " + str + " you are out of control!");
				break;
			}
		}
		pw.close();
	}
}
