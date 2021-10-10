import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static boolean isPalindrome(String s, int start, int end) {
        while (start < end) {
            if (s.charAt(start) != s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            n--;

            String s = br.readLine();
            int left = 0;
            int right = s.length() - 1;

            int type = 0;
            while (left < right) {
                if (s.charAt(left) == s.charAt(right)) {
                    left++;
                    right--;
                } else {
                    if (isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1))
                        type = 1;
                    else
                        type = 2;

                    break;
                }
            }
            sb.append(type);
            sb.append("\n");
        }
        System.out.println(sb);
    }
}