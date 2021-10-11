import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int n;
    static String[] arr;
    static boolean[] visited = new boolean[10];
    static ArrayList<String> answer = new ArrayList<>();

    static void dfs(int cnt, String s) {
        if (cnt == n) {
            answer.add(s);
            return;
        }

        int v = s.charAt(cnt) - '0';
        for (int i = 0; i < 10; i++) {
            if (!visited[i]) {
                if (arr[cnt].equals("<")) {
                    if (v >= i) {
                        continue;
                    }
                } else {
                    if (v <= i)
                        continue;
                }
                visited[i] = true;
                dfs(cnt + 1, s + i);
                visited[i] = false;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = br.readLine().split(" ");


        for (int i = 0; i < 10; i++) {
            visited[i] = true;
            dfs(0, "" + i);
            visited[i] = false;
        }
        System.out.println(answer.get(answer.size() - 1));
        System.out.println(answer.get(0));
    }
}