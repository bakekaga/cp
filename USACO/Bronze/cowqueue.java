import java.util.*;
import java.io.*;

public class cowqueue {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader(new FileReader("cowqueue.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("cowqueue.out")));
		StringTokenizer st = new StringTokenizer(in.readLine());

		int n = Integer.parseInt(st.nextToken());
		if (n == 1) {	
			st = new StringTokenizer(in.readLine());
			pw.print(Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken()));
		}
		else {
			ArrayList<Integer> entryTimes = new ArrayList<Integer>();
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				int e = Integer.parseInt(st.nextToken()), q = Integer.parseInt(st.nextToken());
				map.put(e, q);
				entryTimes.add(e);
			}
			Collections.sort(entryTimes);
			int time = entryTimes.get(0);
			for (int i = 0; i < entryTimes.size() - 1; i++) {
				time+= map.get(entryTimes.get(i));
				if (time <= entryTimes.get(i + 1)) {
					time = entryTimes.get(i + 1);	
				}
				if (i == entryTimes.size() - 2) time+= map.get(entryTimes.get(i + 1));
			}
			pw.print(time);
		}
		pw.close();
	}
}