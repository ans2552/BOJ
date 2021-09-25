import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int[][] arr;
    static int[][] visit;
    static int w;
    static int h;
    static int[] dx = new int[]{0, 0, 1, -1, -1, -1, 1, 1};
    static int[] dy = new int[]{1, -1, 0, 0, -1, 1, 1, -1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            if (w == 0 && h == 0)
                break;
            arr = new int[h][w];
            visit = new int[h][w];
            for (int i = 0; i < h; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < w; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }


            int answer = 0;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (arr[i][j] == 1 && visit[i][j] == 0) {
                        bfs(i, j);
                        answer++;
                    }
                }
            }
            System.out.println(answer);
        }
    }

    static boolean isRange(int x, int y) {
        return x >= 0 && y >= 0 && x < h && y < w;
    }

    static void bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visit[x][y] = 1;

        while (!q.isEmpty()) {
            int fx = q.peek()[0];
            int fy = q.peek()[1];
            q.poll();
            for (int i = 0; i < 8; i++) {
                int nx = fx + dx[i];
                int ny = fy + dy[i];

                if (isRange(nx, ny) && arr[nx][ny] == 1 && visit[nx][ny] == 0) {
                    q.offer(new int[]{nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
}