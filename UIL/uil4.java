import java.io.*;
import java.util.*;
import java.lang.*;

public class uil4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("amogus.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int num = Integer.parseInt(br.readLine());
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < num; i++) {
            String[] s = br.readLine().split(" ");
            map.put(s[0], Integer.parseInt(s[1]));
        }

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            int tot = 0;
            for (String str : s) {
                tot+= map.get(str);
            }
            if (tot >= num - s.length) pw.println("Imposters Win!");
            else pw.println("LOL THESE IMPOSTERS SUCK!");
        }
        pw.close();
    }
}