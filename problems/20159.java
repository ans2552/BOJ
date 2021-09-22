import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int[] arr1 = new int[n / 2];
        int[] arr2 = new int[n / 2];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n / 2; i++) {
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (i == 0) {
                arr1[i] = a;
                arr2[i] = b;
                continue;
            }
            arr1[i] = arr1[i - 1] + a;
            arr2[i] = arr2[i - 1] + b;
        }
        int answer = Math.max(arr1[n / 2 - 1], arr2[n / 2 - 1]);

        for (int i = 1; i < n - 1; i++) {
            int ret;
            if (i % 2 == 0)
                ret = arr1[i / 2 - 1] + arr2[n / 2 - 1] - arr2[i / 2 - 1];
            else {
                ret = arr1[i / 2] + arr2[n / 2 - 2];
                if (i / 2 > 0)
                    ret -= arr2[i / 2 - 1];
            }
            answer = Math.max(answer, ret);
        }
        System.out.println(answer);
    }
}