#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int dist[10001];
int dp[10001][501][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> dist[i];
	}

	dp[0][1][1] = dist[0];
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if (j == 0) {
				dp[i][j][0] = max({ dp[i - 1][j + 1][0], dp[i - 1][j + 1][1],dp[i - 1][j][0] });
			}
			else if (j == 1) {
				dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
				dp[i][j][1] = dp[i - 1][j - 1][0] + dist[i];
			}
			else {
				dp[i][j][0] = max(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
				dp[i][j][1] = dp[i - 1][j - 1][1] + dist[i];
			}
		}
	}
	cout << dp[N - 1][0][0];
}