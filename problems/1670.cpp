#include <iostream>
using namespace std;

int N;
long long dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= N; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			dp[i] += (dp[i - j] * dp[j - 2]) % 987654321;
			dp[i] %= 987654321;
		}
	}
	cout << dp[N];
}