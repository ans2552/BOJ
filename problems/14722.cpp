#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (dp[i - 1][j] % 3 == arr[i][j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
			if (dp[i][j - 1] % 3 == arr[i][j])
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	cout << dp[N][N];
}