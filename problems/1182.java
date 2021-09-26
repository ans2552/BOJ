import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N;
    static int S;
    static int[] arr;
    static int answer = 0;

    static void dfs(int cnt, int sum) {
        if (cnt == N) {
            if (sum == S)
                answer++;
            return;
        }
        dfs(cnt + 1, sum + arr[cnt]);
        dfs(cnt + 1, sum);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dfs(0, 0);

        if (S == 0)
            answer--;
        System.out.println(answer);
    }
}