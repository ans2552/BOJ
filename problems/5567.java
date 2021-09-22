import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[] visit = new int[n + 1];
        ArrayList<Integer>[] list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            list[a].add(b);
            list[b].add(a);
        }

        int answer = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(1);
        visit[1] = 1;

        while (!q.isEmpty()) {
            int node = q.poll();
            int cnt = visit[node];
            if (cnt > 2)
                break;

            for (int next : list[node]) {
                if (visit[next] == 0) {
                    visit[next] = cnt + 1;
                    q.offer(next);
                    answer++;
                }
            }
        }
        System.out.println(answer);
    }
}
