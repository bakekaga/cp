import java.io.*;
import java.util.*;

public class prob11{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());
		String s = "";
		while(st.hasMoreTokens()){
			String m = st.nextToken();

			s += m+" ";
			if(!st.hasMoreTokens() && !m.equals("END")){
				//s+= "\n";
				st = new StringTokenizer(br.readLine());
			}
		}
		String c = "qQwWrRtTyYpPlLkKjJhHgGfFdDsSzZxXcCvVbBnNmM";
		String v =" eEuUiIoOaA";
		
		s = s.substring(0, s.length()-4);
		//pw.println(s);
		String r = "";
		String[] arr = s.split(" ");
		for(int i = 0; i < arr.length; i++){
			String x = arr[i];
			String f = x.substring(0,1);
			String l = "";
			if(!c.contains(x.substring(x.length()-1)) && !v.contains(x.substring(x.length()-1))){
				l = x.substring(x.length()-1);
				x = x.substring(0, x.length()-1);
			}
			if(c.contains(f) && x.length() > 2){
				r+= x.substring(1) + f + "-squeak" + l + " ";
			}else if(v.contains(f)){
				r+= x + "-m" + l + " ";
			}else{
				r+= x + l + " ";
			}
		}
		
		pw.println(r);
		pw.close();
	}
}
