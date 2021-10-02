import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N, M;
    static int[] arr;
    static int[] answer;
    static boolean[] visit;

    static void dfs(int cnt, int start, StringBuilder sb) {
        if (cnt == M) {
            for (int i = 0; i < M; i++) {
                sb.append(answer[i] + " ");
            }
            sb.append("\n");

        } else {
            int num = 0;
            for (int i = start; i < N; i++) {
                if (!visit[i]) {
                    if (num == arr[i]) {
                        continue;
                    }
                    visit[i] = true;
                    answer[cnt] = arr[i];
                    dfs(cnt + 1, i + 1, sb);
                    visit[i] = false;
                    num = arr[i];
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N];
        answer = new int[M];
        visit = new boolean[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        StringBuilder sb = new StringBuilder();

        dfs(0, 0, sb);
        System.out.print(sb);
    }
}