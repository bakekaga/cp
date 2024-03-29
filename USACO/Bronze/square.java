import java.util.*;
import java.io.*;

public class square {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("square.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("square.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] pasture1 = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
		st = new StringTokenizer(br.readLine());
		int[] pasture2 = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
		
		int xmin = Math.min(Math.min(pasture1[0], pasture2[0]), Math.min(pasture1[2], pasture2[2]));
		int xmax = Math.max(Math.max(pasture1[0], pasture2[0]), Math.max(pasture1[2], pasture2[2]));
		int ymin = Math.min(Math.min(pasture1[1], pasture2[1]), Math.min(pasture1[3], pasture2[3]));
		int ymax = Math.max(Math.max(pasture1[1], pasture2[1]), Math.max(pasture1[3], pasture2[3]));
		pw.println(Math.max(ymax - ymin, xmax - xmin) * Math.max(ymax - ymin, xmax - xmin));
		pw.close();
	}
}