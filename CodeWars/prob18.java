import java.io.*;
import java.util.*;

public class prob18 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		String[] arr = br.readLine().split(",");
		String[] elements = new String[arr.length];
		for (int i = 0; i < arr.length; i++) elements[i] = br.readLine();
		String out = "";
		for (int i = 0; i < arr.length; i++) {
			String s = arr[i];
			if (s.charAt(0) == '[') s = s.substring(1);
			if (s.charAt(s.length() - 1) == ']') s = s.substring(0, s.length() - 1);
			String[] commands = s.split(";");
			for (int j = 0; j < commands.length; j++) {
				if (commands[j].indexOf("-") > 0) {
					int first = Integer.parseInt(commands[j].substring(0, commands[j].indexOf("-")));
					int last = Integer.parseInt(commands[j].substring(commands[j].indexOf("-") + 1));
					out+= elements[i].substring(first - 1, last);
				}         
				else {
					int ind = Integer.parseInt(commands[j]);
					if (ind == 0) continue;
					out+= elements[i].charAt(ind > 0 ? ind - 1 : elements[i].length() + ind);
				}
			}
		}
		pw.println(out);
		pw.close();
	}
}
