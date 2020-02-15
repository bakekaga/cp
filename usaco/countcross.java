import java.util.*;
import java.io.*;

/*
ID: bakekaga
LANG: JAVA
TASK: countcross
*/

public class countcross {

	 
    static void shuffle(int[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            int temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static void shuffle(long[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            long temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
 
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }
 
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
	
	static class Node {
		private int x, y;
		private LinkedList<Node> edges = new LinkedList<Node>();
		
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void dfs(Node n, boolean[][] visited) {
		int count = 0;
		for (Node each : n.edges) {
			if (visited[each.x][each.y] == true) {
				count++;
			}
			else {
				visited[each.x][each.y] = true;
				dfs(each, visited);
			}
			if (count == n.edges.size()) return;
		}
	}
		
	public static Node[][] initGraph(int a, int b) {
		Node[][] graph = new Node[a+1][b+1];
		
		for (int i = 1; i < graph.length; i++) {
			for (int j = 1; j < graph[i].length; j++) {
				graph[i][j] = new Node(i, j);
				
				if(i > 1)
				{
					graph[i][j].edges.add(graph[i-1][j]);
					graph[i-1][j].edges.add(graph[i][j]);	
				}
				if(j > 1)
				{
					graph[i][j].edges.add(graph[i][j-1]);
					graph[i][j-1].edges.add(graph[i][j]);
				}
			}
		}
		
		return graph;
	}
    
	public static void main(String[] args) throws FileNotFoundException, IOException {
		FastReader in = new FastReader("countcross.in");
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("countcross.out")));
//		PrintWriter pw = new PrintWriter(System.out);
		
		int n = in.nextInt(), k = in.nextInt(), r = in.nextInt();
		
		boolean[][][] visited = new boolean[k][n+1][n+1];
		Node[][] graph = initGraph(n,n);
		Node[] cows = new Node[k];
	    int pairs = 0;
		
		for (int i = 0; i < r; i++) {
			int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
			graph[x1][y1].edges.remove(graph[x2][y2]);
			graph[x2][y2].edges.remove(graph[x1][y1]);
		}
		
		for (int i = 0; i < k; i++) {
			cows[i] = graph[in.nextInt()][in.nextInt()];
			dfs(cows[i], visited[i]);
			for (int j = 0; j < i; j++) {
				if (visited[j][cows[i].x][cows[i].y] == false) pairs++;
			}
		}
		
		pw.print(pairs);
		pw.close();
	}
}