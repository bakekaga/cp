import java.util.*;
import java.io.*;

public class whereami
{
	public static void main(String[] args) throws IOException
	{
	    BufferedReader br = new BufferedReader(new FileReader("whereami.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("whereami.out"));
		
		int n = Integer.parseInt(br.readLine());
		String str = br.readLine();
		
		for (int i = 1; i <= n; i++) {
			ArrayList<String> s = new ArrayList<String>();
			boolean flag = true;
			for (int j = 0; j <= n - i; j++) {
				if (s.contains(str.substring(j, j + i))) {
					flag = false;
					break;
				}
				s.add(str.substring(j, j + i));
			}
			if (flag) {
				pw.println(i);
				break;
			}
		}
	    
	    br.close();
	    pw.close();

  }
}