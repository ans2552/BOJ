import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static char[][] arr;
    static int h, w;
    static int px, py;
    static int[][] visitFire;

    static Queue<int[]> fq;
    static int[][] visit;

    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static boolean isRange(int x, int y) {
        return x >= 0 && y >= 0 && x < h && y < w;
    }

    static void bfsFire() {
        while (!fq.isEmpty()) {
            int x = fq.peek()[0];
            int y = fq.peek()[1];
            int cnt = visitFire[x][y];

            fq.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isRange(nx, ny) && visitFire[nx][ny] == 0 && arr[nx][ny] != '#') {
                    visitFire[nx][ny] = cnt + 1;
                    fq.offer(new int[]{nx, ny});
                }
            }
        }
    }

    static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{px, py});
        visit[px][py] = 1;

        while (!q.isEmpty()) {
            int x = q.peek()[0];
            int y = q.peek()[1];
            int cnt = visit[x][y];

            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!isRange(nx, ny))
                    return cnt;
                if (visit[nx][ny] == 0 && arr[nx][ny] != '#' && (visitFire[nx][ny] == 0 || visitFire[nx][ny] > cnt + 1)) {
                    visit[nx][ny] = cnt + 1;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());

            fq = new LinkedList<>();
            arr = new char[h][w];
            visit = new int[h][w];
            visitFire = new int[h][w];
            for (int i = 0; i < h; i++) {
                arr[i] = br.readLine().toCharArray();
                for (int j = 0; j < w; j++) {
                    if (arr[i][j] == '@') {
                        px = i;
                        py = j;
                    }
                    if (arr[i][j] == '*') {
                        fq.offer(new int[]{i, j});
                        visitFire[i][j] = 1;
                    }
                }
            }
            bfsFire();
            int answer = bfs();
            if (answer == -1)
                bw.write("IMPOSSIBLE");
            else
                bw.write(Integer.toString(answer));
            bw.write("\n");
        }
        bw.close();
    }
}
