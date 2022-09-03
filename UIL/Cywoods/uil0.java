import java.io.*;
import java.util.*;

public class uil0 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("dryrun.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());

        pw.println(n);
        pw.println();
        pw.println("Team Number: 16");
        pw.println("Team Members: Bruce Le, Donne Su, Albert Zhu");
        pw.println("School Name: Bellaire High School");
        pw.println("Division: Novice");
        pw.close();
    }
}
