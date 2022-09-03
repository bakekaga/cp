import java.io.*;
import java.util.*;

public class Ivan {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("ivan.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());

		List<String> ans = new ArrayList<String>();

		ans.add(st.nextToken());
		for(int i = 0; i < n; i++){
			int exam = i + 1;
			st = new StringTokenizer(br.readLine());
			String guess = st.nextToken();
			int score = 0, attempt = 0, correct = 0;
			for(int j = 0; j < ans.get(0).length(); j++){
				
				String ansSub = ans.get(0).substring(j, j+1);
				if(guess.substring(j, j+1).equals(ansSub)){
					score += 6;
					correct++;
				}

				else if(guess.substring(j, j+1).equals("_")){
					attempt--;
				}

				else
					score -= 2;
				
				attempt++;
			}
			double grade;

			if(attempt == 0)
				grade = 0;
			else
				grade = (double)correct / attempt * 100;
			pw.println("Exam #" + exam + ": " + score + " " + (double)Math.round(grade* 10) / 10);
		}

		
		pw.close();
	}
}