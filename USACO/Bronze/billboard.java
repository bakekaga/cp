import java.io.*;
import java.util.*;
 
public class billboard {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("billboard.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int lx1 = Integer.parseInt(st.nextToken()), ly1 = Integer.parseInt(st.nextToken()), lx2 = Integer.parseInt(st.nextToken()), ly2 = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int cx1 = Integer.parseInt(st.nextToken()), cy1 = Integer.parseInt(st.nextToken()), cx2 = Integer.parseInt(st.nextToken()), cy2 = Integer.parseInt(st.nextToken());
		if (ly1 >= cy1 && ly2 <= cy2 && lx1 >= cx1 && lx2 <= cx2) pw.println(0);

		else if (ly1 >= cy1 && ly2 <= cy2 && lx1 <= cx1 && lx2 <= cx2 && lx2 >= cx1) pw.println((ly2 - ly1) * (cx1 - lx1));
		else if (ly1 >= cy1 && ly2 <= cy2 && lx1 >= cx1 && lx2 >= cx2 && lx1 <= cx2) pw.println((ly2 - ly1) * (lx2 - cx2));

		else if (lx1 >= cx1 && lx2 <= cx2 && ly1 <= cy1 && ly2 <= cy2 && ly2 >= cy1) pw.println((lx2 - lx1) * (cy1 - ly1));
		else if (lx1 >= cx1 && lx2 <= cx2 && ly1 >= cy1 && ly2 >= cy2 && ly1 <= cy2) pw.println((lx2 - lx1) * (ly2 - cy2));

		else pw.println((lx2 - lx1) * (ly2 - ly1));
		pw.close();
	}
}