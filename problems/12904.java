import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        String t = br.readLine();

        LinkedList<Character> T = new LinkedList<Character>();
        for (char c : t.toCharArray()) {
            T.add(c);
        }
        boolean reverse = false;

        while (s.length() < T.size()) {
            if (reverse) {
                if (T.peekFirst() != 'A') {
                    reverse = false;
                }
                T.pollFirst();
            } else {
                if (T.peekLast() != 'A') {
                    reverse = true;
                }
                T.pollLast();
            }
        }

        int answer = 1;
        for (char c : s.toCharArray()) {
            if (reverse) {
                if (c != T.pollLast()) {
                    answer = 0;
                    break;
                }
            } else {
                if (c != T.pollFirst()) {
                    answer = 0;
                    break;
                }
            }
        }
        bw.write(Integer.toString(answer));
        bw.close();
    }
}
