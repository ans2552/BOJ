import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    static int[] arr = new int[30];
    static char answer = 'o';

    public static void dfs(int i, int j) {
        if (i == 1) {
            if (j == 1)
                answer = 'm';
            return;
        }

        if (j <= arr[i - 1])
            dfs(i - 1, j);
        else if (j <= arr[i - 1] + i + 2) {
            if (j == arr[i - 1] + 1)
                answer = 'm';
        } else {
            dfs(i - 1, j - arr[i - 1] - i - 2);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        for (int i = 1; i < 30; i++) {
            arr[i] = 2 * arr[i - 1] + i + 2;
            if (arr[i] >= n) {
                dfs(i, n);
                break;
            }
        }
        System.out.println(answer);
    }
}