import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int N;
    static int K;
    static int[] health;
    static int[] robot;

    static void rotate() {
        int temp = health[2 * N - 1];
        for (int i = 2 * N - 2; i >= 0; i--) {
            health[i + 1] = health[i];
        }
        health[0] = temp;

        temp = robot[2 * N - 1];
        for (int i = 2 * N - 2; i >= 0; i--) {
            robot[i + 1] = robot[i];
        }
        robot[0] = temp;
    }

    static int check() {
        int ret = 0;
        for (int i = 0; i < 2 * N; i++) {
            if (health[i] == 0)
                ret++;
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        health = new int[2 * N];
        robot = new int[2 * N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 2 * N; i++) {
            health[i] = Integer.parseInt(st.nextToken());
        }

        int answer = 0;
        while (true) {
            answer++;
            //한칸 회전
            rotate();

            //N가면 버리기
            robot[N - 1] = 0;

            //회전하는 방향으로 이동가능하면 이동
            for (int i = N - 2; i >= 0; i--) {
                if (robot[i] == 0)
                    continue;
                if (robot[i + 1] == 0 && health[i + 1] > 0) {
                    robot[i + 1] = 1;
                    robot[i] = 0;
                    health[i + 1]--;
                }
            }
            //N가면 버리기
            robot[N - 1] = 0;

            //올리는위치에 올리기
            if (health[0] > 0) {
                robot[0] = 1;
                health[0]--;
            }

            if (check() >= K)
                break;
        }
        System.out.println(answer);
    }
}