import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static ArrayList<ArrayList<int[]>> adj;
    static boolean[] visit;
    static int answer;

    static void dfs(int a, int b, int ans, int max) {
        if (a == b) {
            answer = ans - max;
            return;
        }

        for (int[] next : adj.get(a)) {
            if (visit[next[0]])
                continue;
            visit[next[0]] = true;
            dfs(next[0], b, ans + next[1], Math.max(max, next[1]));
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        visit = new boolean[N + 1];
        adj = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            ArrayList<int[]> list = new ArrayList<>();
            adj.add(list);
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            adj.get(s).add(new int[]{e, w});
            adj.get(e).add(new int[]{s, w});
        }

        visit[a] = true;
        dfs(a, b, 0, 0);

        System.out.println(answer);
    }
}