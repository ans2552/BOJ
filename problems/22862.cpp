#include <algorithm>
#include <iostream>
using namespace std;

int N, K;
int arr[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int cnt = 0;

    if (arr[0] % 2 == 1) cnt++;

    int answer = 0;
    while (right < N) {
        if (cnt < K) {
            right++;
            if (right < N && arr[right] % 2 == 1) cnt++;
            answer = max(answer, right - left - cnt);
        } else if (cnt == K) {
            right++;
            while (right < N && arr[right] % 2 == 0) {
                right++;
            }
            cnt++;
            answer = max(answer, right - left - K);
        } else {
            while (1) {
                if (arr[left] % 2 == 0)
                    left++;
                else
                    break;
            }
            left++;
            cnt--;
        }
    }
    cout << answer;
}