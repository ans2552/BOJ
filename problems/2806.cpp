#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
int dp[1000000][2]; //0이 A, 1이 B
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cin >> s;

	if (s[0] == 'A') {
		dp[0][0] = 0;
		dp[0][1] = 1;
	}
	else {
		dp[0][0] = 1;
		dp[0][1] = 0;
	}

	for (int i = 1; i < N; i++) {
		if (s[i] == 'A') {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
			dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
		}
		else {
			dp[i][0] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
			dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
		}
	}

	cout << dp[N - 1][0];
}