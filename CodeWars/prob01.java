import java.io.*;
import java.util.*;

public class prob01 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		// StringTokenizer st = new StringTokenizer(br.readLine());
		String name = br.readLine();
		pw.println("Clap your hands together and give it up for " + name + "!\n");
		pw.close();
	}
}
