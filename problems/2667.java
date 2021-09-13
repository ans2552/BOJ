import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

    static int N;
    static int[][] arr;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static int[][] visit;
    static ArrayList<Integer> ans = new ArrayList<>();

    public static boolean isRange(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < N;
    }

    public static void bfs(int x, int y) {
        LinkedList<int[]> q = new LinkedList<int[]>();
        q.add(new int[]{x, y});
        visit[x][y] = 1;

        int cnt = 0;
        while (!q.isEmpty()) {
            cnt++;
            int fx = q.peekFirst()[0];
            int fy = q.peekFirst()[1];
            q.pollFirst();

            for (int i = 0; i < 4; i++) {
                int nx = fx + dx[i];
                int ny = fy + dy[i];
                if (isRange(nx, ny) && arr[nx][ny] == 1 && visit[nx][ny] == 0) {
                    q.addLast(new int[]{nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
        ans.add(cnt);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        visit = new int[N][N];

        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < N; j++) {
                arr[i][j] = s.charAt(j) - '0';
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] != 0 && visit[i][j] == 0) {
                    bfs(i, j);
                }
            }
        }

        bw.write(ans.size() + "\n");
        Collections.sort(ans);
        for (int a : ans) {
            bw.write(a + "\n");
        }
        bw.close();
    }
}
