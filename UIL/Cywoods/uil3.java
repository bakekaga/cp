import java.io.*;
import java.util.*;

public class uil3 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("yourmom.dat"));
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] jokes = new String[4];
            int max = 0, maxind = 0;
            for (int j = 0; j < 4; j++) {
                int sum = 0;
                jokes[j] = br.readLine();
                for (int k = 9; k < jokes[j].length(); k++) {
                    if (jokes[j].charAt(k) != ' ') sum+= jokes[j].charAt(k);
                }
                int ind = jokes[j].indexOf("is");
                if (ind > 0) {
                    sum-= 'i';
                    sum-= 's';
                }
                if (sum > max) {
                    max = sum;
                    maxind = j;
                }
            }
            br.readLine();
            pw.println("The best Your Mom Joke is: " + jokes[maxind]);
        }

        pw.close();
    }
}