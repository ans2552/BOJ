import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0;
        int right = N - 1;
        int answer = 200000000;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum < 0) {
                if (Math.abs(answer) > Math.abs(sum))
                    answer = sum;
                left++;
            } else if (sum > 0) {
                if (Math.abs(answer) > Math.abs(sum))
                    answer = sum;
                right--;
            } else {
                answer = 0;
                break;
            }
        }
        System.out.println(answer);
    }
}