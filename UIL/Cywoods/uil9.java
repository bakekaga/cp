// import java.io.*;
// import java.util.*;

// public class uil9 {
//     public static void main(String[] args) throws IOException {
//         // BufferedReader br = new BufferedReader(new FileReader("grades.dat"));
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         PrintWriter pw = new PrintWriter(System.out);

//         StringTokenizer st = new StringTokenizer(br.readLine());
//         int n = Integer.parseInt(st.nextToken());
//         st = new StringTokenizer(br.readLine());

//         int s = Integer.parseInt(st.nextToken());
//         int g = Integer.parseInt(st.nextToken());

//         for(int i = 0; i < n; i++){
//             String[] str = br.readLine().split(" ");
//             double highest = 0;
//             String hname = "";
//             double grade = 0;
//             double sum = 0;
//             int exempt = 0;
//             for(int k = 1; k < s; k++){
//                 if(str[k].equals("X")){
//                     str[k] = "0";
//                     exempt++;
//                 }
//                 if(str[k].equals("Z"))
//                     str[k] = "0";
//                 sum += Integer.parseInt(str[k]);
//             }
//             grade = sum / (grade - exempt);
//             if(grade > highest){
//                 highest = grade;
//                 hname = str[0];
//             }
//             pw.println(hname + " " + highest);
            
//         }
        

    
//         pw.close();
//     }
// }