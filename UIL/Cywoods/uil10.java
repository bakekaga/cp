import java.io.*;
import java.util.*;

public class uil10 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("curling.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int tt = 0; tt < t; tt++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            double d = Double.parseDouble(st.nextToken());
            TreeMap<Double, Double> map = new TreeMap<Double, Double>();
            for (int i = 0; i < n; i++) {
                double x = Double.parseDouble(br.readLine());
                map.put(Math.abs(x - d), x);
            }
            String out = "----------";
            ArrayList<Double> arr = new ArrayList<Double>();
            for (Double x : map.keySet()) {
                arr.add(map.get(x));
            }
            for (int i = arr.size() - 1; i >= 0; i--) {
                out = arr.get(i) + ('\n' + out);
            }
            pw.println(out);
        }
        pw.close();
    }
}