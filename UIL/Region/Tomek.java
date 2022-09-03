import java.io.*;
import java.util.*;

public class Tomek {
	static class Pair {
		int x, y;
		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("tomek.dat"));
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(br.readLine());

		int t = Integer.parseInt(st.nextToken());
		int[] dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
		for (int tt = 1; tt <= t; tt++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
			char[][] grid = new char[n][m];
			boolean[][] vis = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				grid[i] = br.readLine().toCharArray();
			}
			int comps = 0;
			ArrayList<Integer> sizes = new ArrayList<Integer>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (vis[i][j] || grid[i][j] == 'W') continue;
					boolean island = true;
					Stack<Pair> dfs = new Stack<Pair>();
					dfs.push(new Pair(i, j));
					int sz = 0;
					while (!dfs.isEmpty()) {
						sz++;
						Pair top = dfs.pop();
						vis[top.x][top.y] = true;
						if (top.x == 0 || top.x == n - 1 || top.y == 0 || top.y == m - 1) {
							island = false;
						}
						for (int k = 0; k < 4; k++) {
							int x = top.x + dx[k], y = top.y + dy[k];
							if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || grid[x][y] != '.') continue;
							dfs.push(new Pair(x, y));
						}
					}
					if (island) {
						comps++;
						sizes.add(sz);
					}
				}
			}
			pw.println("Case #" + tt + ": " + comps);
			Collections.sort(sizes);
			if (sizes.size() > 0) for (int x = sizes.size() - 1; x >= 0; x--) pw.print(sizes.get(x) + " ");
			else pw.print("NONE");
			pw.println();
		}
		pw.close();
	}
}