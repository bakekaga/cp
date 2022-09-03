import java.io.*;
import java.util.*;

public class Kristina {
	public static void main(String[] args) throws IOException {
		// BufferedReader br = new BufferedReader(new FileReader("kristina.dat"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		for (int t = 0; t < n; t++) {
			String[] inp = br.readLine().split(" ");
			String ops = "*/+-^";
			if (inp[0].equals("PRE")) {
				// Stack<String> stack = new Stack<String>();	
				// ArrayList<Integer> lst = new ArrayList<Integer>();
				// for (int i = 1; i < inp.length; i++) {
				// 	if (ops.indexOf(inp[i]) >= 0) stack.add(inp[i]);
				// 	else {
				// 		lst.add(Integer.parseInt(inp[i]));
				// 		if (lst.size() == 2) {
				// 			String op = stack.pop();
				// 			if (op.equals("+")) lst.set(0, lst.get(0) + lst.get(1));
				// 			else if (op.equals("-")) lst.set(0, lst.get(0) - lst.get(1));
				// 			else if (op.equals("*")) lst.set(0, lst.get(0) * lst.get(1));
				// 			else if (op.equals("/")) lst.set(0, lst.get(0) / lst.get(1));
				// 			else if (op.equals("^")) {
				// 				int out = 1;
				// 				while (lst.get(1) > 0) {
				// 					if ((lst.get(1) & 1) != 0) {
				// 						out*= lst.get(0);
				// 					}
				// 					out*= out;
				// 					lst.set(1, lst.get(1) >> 1);
				// 				}
				// 				lst.set(0, out);
				// 			}
				// 			lst.remove(1);
				// 		}
				// 	}
				// }
				// pw.println(lst.get(0));
				Stack<Integer> stack = new Stack<Integer>();	
				for (int i = 1; i < inp.length; i++) {
					if (ops.indexOf(inp[i]) > 0) stack.add(Integer.parseInt(inp[i]));
					else {
						int sec = stack.pop(), cur = stack.pop();
						if (inp[i].equals("+")) cur = cur + sec;
						else if (inp[i].equals("-")) cur = cur - sec;
						else if (inp[i].equals("*")) cur = cur * sec;
						else if (inp[i].equals("/")) cur = cur / sec;
						else if (inp[i].equals("^")) {
							int out = 1;
							while (sec > 0) {
								if ((sec & 1) != 0) {
									out*= cur;
								}
								out*= out;
								sec >>= 1;
							}
							cur = out;
						}
						stack.add(cur);
					}
				}
				pw.println(stack.pop());
			}
			else {
				Stack<Integer> stack = new Stack<Integer>();	
				for (int i = 1; i < inp.length; i++) {
					if (ops.indexOf(inp[i]) == -1) stack.add(Integer.parseInt(inp[i]));
					else {
						int sec = stack.pop(), cur = stack.pop();
						if (inp[i].equals("+")) cur = cur + sec;
						else if (inp[i].equals("-")) cur = cur - sec;
						else if (inp[i].equals("*")) cur = cur * sec;
						else if (inp[i].equals("/")) cur = cur / sec;
						else if (inp[i].equals("^")) {
							int out = 1;
							while (sec > 0) {
								if ((sec & 1) != 0) {
									out*= cur;
								}
								out*= out;
								sec >>= 1;
							}
							cur = out;
						}
						stack.add(cur);
					}
				}
				pw.println(stack.pop());
			}
		}
		pw.close();
	}
}