import java.io.*;
import java.util.*;

public class uil7 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("cps.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long n = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(br.readLine());
                String dir = st.nextToken();
                int amt = Integer.parseInt(st.nextToken());
                if (dir.equals("up")) {
                    y+= amt;
                }
                else if (dir.equals("down")) {
                    y-= amt;
                }
                else if (dir.equals("right")) {
                    x+= amt;
                }
                else if (dir.equals("left")) {
                    x-= amt;
                }
            }
            pw.println(x + " " + y);
        }
        pw.close();
    }
}