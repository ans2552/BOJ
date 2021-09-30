import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int[][] arr;
    static int[] answer = new int[3];

    static void dfs(int n, int x, int y) {
        int now = arr[x][y];
        boolean check = true;
        f1:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (now != arr[x + i][y + j]) {
                    check = false;
                    break f1;
                }
            }
        }
        if (check) {
            answer[now + 1]++;
        } else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    dfs(n / 3, x + n / 3 * i, y + n / 3 * j);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        arr = new int[N][N];

        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(N, 0, 0);

        for (int i = 0; i < 3; i++) {
            System.out.println(answer[i]);
        }
    }
}