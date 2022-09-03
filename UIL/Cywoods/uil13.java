import java.io.*;
import java.util.*;

public class uil13 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("sammy10.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String cur = br.readLine();
            boolean flag = false;
            while (!cur.equals("=")) {
                if (cur.indexOf("Stroud") >= 0) flag = true;
                cur = br.readLine();
            }
            if (flag) pw.println("Bravo seven commencing extraction");
            else pw.println("Bravo seven remaining dark");
        }
        pw.close();
    }
}