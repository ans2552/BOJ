#include <iostream>
using namespace std;
int T, n, m;
long long dp[11][2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 2000; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j <= 2000; j++) {
			for (int k = 1; k <= j / 2; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	cin >> T;
	while (T--) {
		cin >> n >> m;
		long long answer = 0;
		for (int i = 1; i <= m; i++) {
			answer += dp[n][i];
		}
		cout << answer << '\n';
	}
}