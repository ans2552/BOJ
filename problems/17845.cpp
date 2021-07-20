#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> subject[100001];
int dp[1001][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> subject[i].first >> subject[i].second;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			if (j >= subject[i].second) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - subject[i].second] + subject[i].first);
			}
			else {
				dp[i][j] =  dp[i - 1][j];
			}
		}
	}
	cout << dp[K][N];
}