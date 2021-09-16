import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    static final int MAX = 123456 * 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] prime = new int[MAX + 1];
        prime[1] = 1;
        for (int i = 2; i * i <= MAX; i++) {
            if (prime[i] == 0) {
                for (int j = 2; j * i <= MAX; j++) {
                    prime[j * i] = 1;
                }
            }
        }

        while (true) {
            int N = Integer.parseInt(br.readLine());
            if (N == 0)
                break;

            int answer = 0;
            for (int i = N + 1; i <= 2 * N; i++) {
                if (prime[i] == 0) {
                    answer++;
                }
            }
            bw.write(Integer.toString(answer));
            bw.write("\n");
        }
        bw.close();
    }
}