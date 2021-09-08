#include <algorithm>
#include <iostream>
using namespace std;

int N, K;
int arr[200000];
int cnt[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int answer = 0;
    while (right < N) {
        if (cnt[arr[right]] < K) {
            cnt[arr[right]]++;
            right++;
        } else if (cnt[arr[right]] == K) {
            while (arr[left] != arr[right]) {
                cnt[arr[left]]--;
                left++;
            }
            cnt[arr[left]]--;
            left++;
        }
        answer = max(answer, right - left);
    }
    cout << answer;
}