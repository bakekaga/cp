import java.io.*;
import java.util.*;
import java.lang.*;

public class uil11 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("aplace.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            String str = st.nextToken();
            for(int k = 0; k < str.length(); k++){
                if((k + 1) % x == 0)
                    pw.println(str.substring(k, k+1));
                else
                    pw.print(str.substring(k, k+1) + " ");
            }
            pw.println();
        }
        pw.close();
    }
}