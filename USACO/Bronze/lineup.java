import java.util.*;
import java.io.*;

public class lineup {

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("lineup.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("lineup.out"));
        
        int n = Integer.parseInt(br.readLine());
        TreeMap<String, Integer> map = new TreeMap<String, Integer>();
        map.put("Beatrice", 8);
        map.put("Belinda", 8);
        map.put("Bella", 8);
        map.put("Bessie", 8);
        map.put("Betsy", 8);
        map.put("Blue", 8);
        map.put("Buttercup", 8);
        map.put("Sue", 8);
        ArrayList<LinkedList<String>> groups = new ArrayList<LinkedList<String>>(n);

        for (int i = 0; i < n; i++) {
            String[] in = br.readLine().split(" ");
            LinkedList<String> a = new LinkedList<String>();
            a.add(in[0]);
            a.add(in[5]);
            map.remove(in[0]);
            map.remove(in[5]);
            groups.add(a);
        }

        for (int i = 0; i < groups.size(); i++) {
            boolean matchFound = true;
            while (matchFound) {
                matchFound = false;
                for (int j = i + 1; j < groups.size(); j++) {
                    if (groups.get(j).getFirst().equals(groups.get(i).getLast())) {
                        groups.get(j).removeFirst();
                        groups.get(i).addAll(groups.get(j));
                        groups.remove(j);
                        j--;
                        matchFound = true;
                    }
                    else if (groups.get(j).getLast().equals(groups.get(i).getFirst())) {
                        groups.get(j).removeLast();
                        groups.get(i).addAll(0, groups.get(j));
                        groups.remove(j);
                        j--;
                        matchFound = true;
                    }
                    else if (groups.get(j).getLast().equals(groups.get(i).getLast())) {
                        groups.get(j).removeLast();
                        reverse(groups.get(j));
                        groups.get(i).addAll(groups.get(j));
                        groups.remove(j);
                        j--;
                        matchFound = true;
                    }
                    else if (groups.get(j).getFirst().equals(groups.get(i).getFirst())) {
                        groups.get(j).removeFirst();
                        reverse(groups.get(j));
                        groups.get(i).addAll(0, groups.get(j));
                        groups.remove(j);
                        j--;
                        matchFound = true;
                    }
                }
            }
        }

        for (int i = 0; i < groups.size(); i++) {
            if (groups.get(i).getLast().compareTo(groups.get(i).getFirst()) < 0) {
                reverse(groups.get(i));
            }
            map.put(groups.get(i).getFirst(), i);
        }

        for (Map.Entry<String, Integer> e : map.entrySet()) {
            if (e.getValue() == 8) pw.println(e.getKey());
            else {
                for (String s : groups.get(e.getValue())) {
                    pw.println(s);
                }
            }
        }
        pw.close();
    }

    static void reverse(LinkedList<String> list) {
        String temp = "";
        for (int i = 0; i < list.size() / 2; i++) {
            temp = list.get(i);
            list.set(i, list.get(list.size() - i - 1));
            list.set(list.size() - i - 1, temp);
        }
    }
}