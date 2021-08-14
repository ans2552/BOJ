#include <iostream>
using namespace std;

int N, M;
int arr[2001];
int dp[2001][2001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, e;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++) {
            if (arr[j] == arr[j + i]) {
                if (i == 1)
                    dp[j][j + i] = 1;
                else
                    dp[j][j + i] = dp[j + 1][j + i - 1];
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}
