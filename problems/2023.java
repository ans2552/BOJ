import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N;

    static boolean isPrime(int num) {
        if (num == 1)
            return false;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    static void dfs(int num, int cnt) throws Exception {
        if (cnt == N) {
            bw.write(Integer.toString(num));
            bw.write("\n");
            return;
        }

        for (int i = 1; i <= 9; i++) {
            int num2 = num * 10 + i;
            if (isPrime(num2))
                dfs(num2, cnt + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        dfs(2, 1);
        dfs(3, 1);
        dfs(5, 1);
        dfs(7, 1);
        bw.close();
    }
}