import java.io.*;
import java.util.*;

public class uil5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("counting.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());

        for (int tt = 0; tt < t; tt++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
            for (int i = 0; i < n; i++) {
                int cur = Integer.parseInt(st.nextToken());
                if (map.containsKey(cur)) {
                    map.put(cur, map.get(cur) + 1);
                }
                else {
                    map.put(cur, 1);
                }
            }
            ArrayList<Integer> freqs = new ArrayList<Integer>();
            for (Integer i : map.keySet()) freqs.add(map.get(i));
            Collections.sort(freqs);
            ArrayList<Integer> best = new ArrayList<Integer>();
            for (int i = freqs.size() - 1; i >= Math.max(0, freqs.size() - 5); i--) {
                best.add(freqs.get(i));
            }
            for (int j = 0; j < best.size(); j++) {
                for (Integer i : map.keySet()) {
                    if (best.get(j) == map.get(i)) {
                        pw.println(i + " " + map.get(i));
                        map.remove(i);
                        break;
                    }
                }
            }
            pw.println();
        }
        pw.close();
    }
}