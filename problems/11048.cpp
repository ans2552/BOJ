#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1000][1000];
int dp[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i > 0 && j > 0)
				dp[i][j] = max(dp[i][j], max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + arr[i][j]);
			else if (i > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			else if (j > 0)
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
		}
	}

	cout << dp[N - 1][M - 1];   
}