import java.util.*;
import java.io.*;

public class sort
{
	static class Event implements Comparable<Event> {
		int ind, val;
		public Event(int i, int v) {
			ind = i;
			val = v;
		}
		public int compareTo(Event a) {
			return this.val == a.val ? this.ind - a.ind : this.val - a.val;
		}
	}
	
	public static void main(String[] args) throws IOException {	
	    BufferedReader br = new BufferedReader(new FileReader("sort.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("sort.out"));
		
		int n = Integer.parseInt(br.readLine());
		ArrayList<Event> arr = new ArrayList<Event>();
		for (int i = 0; i < n; i++) {
			arr.add(new Event(i, Integer.parseInt(br.readLine())));
		}
		Collections.sort(arr);
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = Math.max(ans, arr.get(i).ind - i);
		}
		pw.println(ans + 1);
		pw.close();
	}
}