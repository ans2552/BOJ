import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    static int n, m;
    static int[][] arr;
    static int[][] visit;

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};


    static boolean isRange(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        visit = new int[n][m];

        int sx = 0, sy = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }
        }

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{sx, sy});
        visit[sx][sy] = 1;
        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            int cnt = visit[x][y];
            q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isRange(nx, ny) && visit[nx][ny] == 0 && arr[nx][ny] == 1) {
                    q.offer(new int[]{nx, ny});
                    visit[nx][ny] = cnt + 1;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1)
                    if (visit[i][j] == 0)
                        sb.append(-1);
                    else
                        sb.append(visit[i][j] - 1);
                else
                    sb.append(0);
                sb.append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }
}