import java.io.*;
import java.util.*;
import java.lang.*;

public class uil12 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("shift.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int shift = Integer.parseInt(st.nextToken());
            String str = br.readLine();

            String newstr = str.substring(str.length() - shift) + str.substring(0, str.length() - shift);
            for(int k = newstr.length() - 1; k >= 0 ; k--){
                pw.print(newstr.substring(k, k + 1));
            }
            pw.println();
        }
        pw.close();
    }
}