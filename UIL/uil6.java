import java.io.*;
import java.util.*;

public class uil6 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("drift.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());

        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long l = Integer.parseInt(st.nextToken()), h = Integer.parseInt(st.nextToken());
            double ans = Math.sqrt(h * h - l * l);
            ans*= 10000;
            ans = Math.round(ans);
            ans/= 10000;
            String bruh = "" + ans;
            pw.print(bruh);
            if (bruh.indexOf('.') > bruh.length() - 5) {
                for (int j = 0; j < bruh.indexOf('.') - (bruh.length() - 5); j++) pw.print(0);
            }
            pw.println();
            
        }
        pw.close();
    }
}