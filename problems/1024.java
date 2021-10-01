import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int t;
        int x = -1;
        int iter = -1;
        for (int i = L; i <= 100; i++) {
            t = (i - 1) * i / 2;
            if ((N - t) % i == 0 && (N - t) / i >= 0) {
                x = (N - t) / i;
                iter = i;
                break;
            }
        }

        if (x == -1)
            System.out.println(-1);
        else {
            for (int i = 0; i < iter; i++) {
                System.out.println(x + i);
            }
        }
    }
}