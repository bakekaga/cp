import java.io.*;
import java.util.*;

public class searchingforsoulmates {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());
        for (int tt = 0; tt < t; tt++) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken()), b = Long.parseLong(st.nextToken());
            ArrayList<long[]> asteps = new ArrayList<long[]>(), bsteps = new ArrayList<long[]>();
            for (long cnt = 0, cura = a; cura < b;) {
                asteps.add(new long[]{cura, cnt});
                cnt++;
                cura*= 2;
            }
            for (long cnt = 0, cura = a; cura > 0; cnt++) {
                asteps.add(new long[]{cura, cnt});
                if ((cura % 2) == 1 && cura != 1) {
                    cura = (cura + 1) / 2;
                    cnt++;
                }
                else cura/= 2;
            }
            for (long cnt = 0, curb = b; curb < a;) {
                bsteps.add(new long[]{curb, cnt});
                cnt++;
                curb*= 2;
            }
            for (long cnt = 0, curb = b; curb > 0; cnt++) {
                bsteps.add(new long[]{curb, cnt});
                if ((curb % 2) == 1 && curb != 1) {
                    curb = (curb - 1) / 2;
                    cnt++;
                }
                else curb/= 2;
            }

            long ans = Long.MAX_VALUE;
            for (int i = 0; i < asteps.size(); i++) {
                for (int j = 0; j < bsteps.size(); j++) {
                    if (asteps.get(i)[0] <= bsteps.get(j)[0]) ans = Math.min(ans, bsteps.get(j)[1] + asteps.get(i)[1] + bsteps.get(j)[0] - asteps.get(i)[0]);
                }
            }

            pw.println(ans);
        }
        pw.close();
    }
}