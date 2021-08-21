import java.util.*;
import java.io.*;

public class billboard {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader(new FileReader("billboard.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
//		Scanner in = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(in.readLine());
		int x1 = Integer.parseInt(st.nextToken());
		int y1 = Integer.parseInt(st.nextToken());
		int x2 = Integer.parseInt(st.nextToken());
		int y2 = Integer.parseInt(st.nextToken());
		int[][] board1 = {{x1, y1}, {x2, y2}};
		
		st = new StringTokenizer(in.readLine());
		x1 = Integer.parseInt(st.nextToken());
		y1 = Integer.parseInt(st.nextToken());
		x2 = Integer.parseInt(st.nextToken());
		y2 = Integer.parseInt(st.nextToken());
		int[][] board2 = {{x1, y1}, {x2, y2}};
		
		st = new StringTokenizer(in.readLine());
		x1 = Integer.parseInt(st.nextToken());
		y1 = Integer.parseInt(st.nextToken());
		x2 = Integer.parseInt(st.nextToken());
		y2 = Integer.parseInt(st.nextToken());
		int[][] truck = {{x1, y1}, {x2, y2}};
		int truckx1 = 0, truckx2 = 0, trucky1 = 0, trucky2 = 0;
		
		// determine truckx1
		if (truck[0][0] > board1[0][0] && truck[0][0] < board1[1][0]) {
			if (truck[1][0] > board1[0][0] && truck[1][0] < board1[1][0]) truckx1 = truck[1][0] - truck[0][0];
			else truckx1 = board1[1][0] - truck[0][0];
		}
		else if (truck[0][0] < board1[0][0] && truck[1][0] > board1[1][0]) {
			truckx1 = board1[1][0] - board1[0][0];
		}
		else if (truck[1][0] > board1[0][0] && truck[1][0] < board1[1][0]) {
			if (truck[0][0] > board1[0][0] && truck[0][0] < board1[1][0]) truckx1 = truck[1][0] - truck[0][0];
			else truckx1 = truck[1][0] - board1[0][0];
		}
		
		// determine trucky1
		if (truck[0][1] > board1[0][1] && truck[0][1] < board1[1][1]) {
			if (truck[1][1] > board1[0][1] && truck[1][1] < board1[1][1]) trucky1 = truck[1][1] - truck[0][1];
			else trucky1 = board1[1][1] - truck[0][1];
		}
		else if (truck[0][1] < board1[0][1] && truck[1][1] > board1[1][1]) {
			trucky1 = board1[1][1] - board1[0][1];
		}
		else if (truck[1][1] > board1[0][1] && truck[1][1] < board1[1][1]) {
			if (truck[0][1] > board1[0][1] && truck[0][1] < board1[1][1]) trucky1 = truck[1][1] - truck[0][1];
			else trucky1 = truck[1][1] - board1[0][1];
		}
		
		// determine truckx2
		if (truck[0][0] > board2[0][0] && truck[0][0] < board2[1][0]) {
			if (truck[1][0] > board2[0][0] && truck[1][0] < board2[1][0]) truckx2 = truck[1][0] - truck[0][0];
			else truckx2 = board2[1][0] - truck[0][0];
		}
		else if (truck[0][0] < board2[0][0] && truck[1][0] > board2[1][0]) {
			truckx2 = board2[1][0] - board2[0][0];
		}
		else if (truck[1][0] > board2[0][0] && truck[1][0] < board2[1][0]) {
			if (truck[0][0] > board2[0][0] && truck[0][0] < board2[1][0]) truckx2 = truck[1][0] - truck[0][0];
			else truckx2 = truck[1][0] - board2[0][0];
		}
		
		// determine trucky2
		if (truck[0][1] > board2[0][1] && truck[0][1] < board2[1][1]) {
			if (truck[1][1] > board2[0][1] && truck[1][1] < board2[1][1]) trucky2 = truck[1][1] - truck[0][1];
			else trucky2 = board2[1][1] - truck[0][1];
		}
		else if (truck[0][1] < board2[0][1] && truck[1][1] > board2[1][1]) {
			trucky2 = board2[1][1] - board2[0][1];
		}
		else if (truck[1][1] > board2[0][1] && truck[1][1] < board2[1][1]) {
			if (truck[0][1] > board2[0][1] && truck[0][1] < board2[1][1]) trucky2 = truck[1][1] - truck[0][1];
			else trucky2 = truck[1][1] - board2[0][1];
		}

//		pw.println(truckx1);
//		pw.println(trucky1);
//		pw.println(truckx2);
//		pw.println(trucky2);
		pw.println(Math.abs(board1[0][1] - board1[1][1]) * Math.abs(board1[0][0] - board1[1][0])
		 + Math.abs(board2[0][1] - board2[1][1]) * Math.abs(board2[0][0] - board2[1][0])
		 - Math.abs(truckx1 * trucky1) - Math.abs(truckx2 * trucky2));
		pw.close();
	}
}