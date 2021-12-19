import java.io.*;
import java.util.*;

public class uil20 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("bye.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x >= 62) pw.println("Goodbye World");
            else pw.println("Flying smoothly!");
        }
        pw.close();
    }
}