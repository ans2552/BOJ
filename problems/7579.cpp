#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int m[100];
int c[100];
int dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 10000; j >= 0; j--) {
			if (c[i] <= j) {
				dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
			}
		}
	}

	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M) {
			cout << i;
			break;
		}
	}
}