import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        while (true) {
            String s = br.readLine();

            String ans = "yes\n";
            Stack<Character> st = new Stack<>();
            if (s.equals("."))
                break;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(' || s.charAt(i) == '[') {
                    st.push(s.charAt(i));
                } else if (s.charAt(i) == ')' || s.charAt(i) == ']') {
                    if (st.isEmpty()) {
                        ans = "no\n";
                        break;
                    }
                    char c = st.pop();
                    if (c == '(' && s.charAt(i) == ')')
                        continue;
                    if (c == '[' && s.charAt(i) == ']')
                        continue;

                    ans = "no\n";
                    break;
                }
            }
            if (!st.isEmpty())
                ans = "no\n";
            sb.append(ans);

        }
        System.out.println(sb);
    }
}