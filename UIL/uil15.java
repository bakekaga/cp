import java.io.*;
import java.util.*;

public class uil15 {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("tabletennis.dat"));
        // Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        while (sc.hasNext()) {
            String str = sc.nextLine();
            String e = str.substring(str.length() - 1);
            String ans = "";
            if (e.equals("P")) ans = "Prancer";
            else if (e.equals("D")) ans = "Dasher";
            else if (e.equals("C")) ans = "Comet";
            else if (e.equals("V")) ans = "Vixen";
            pw.println(ans);
        }
        sc.close();
        pw.close();
    }
}