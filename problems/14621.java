import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static class Edge implements Comparable<Edge> {
        int start;
        int end;
        int cost;

        public Edge(int start, int end, int cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return cost - o.cost;
        }
    }

    static int[] parent;

    static int getParent(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = getParent(parent[a]);
    }

    static boolean union(int a, int b) {
        int pa = getParent(a);
        int pb = getParent(b);

        if (pa != pb) {
            parent[pa] = pb;
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        char[] univ = new char[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            univ[i] = st.nextToken().charAt(0);
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            pq.offer(new Edge(a, b, c));
        }

        int answer = 0;
        int cnt = 0;
        while (!pq.isEmpty()) {
            Edge now = pq.poll();
            if (univ[now.start] == univ[now.end])
                continue;
            if (union(now.start, now.end)) {
                answer += now.cost;
                cnt++;
                if (cnt == N - 1)
                    break;
            }
        }
        if (cnt == N - 1)
            System.out.println(answer);
        else
            System.out.println(-1);
    }
}