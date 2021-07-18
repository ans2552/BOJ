#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int N, M;
int answer;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		memset(dp, 0, sizeof(dp));
		answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					int m = 100000;
					m = min({ m, dp[i - 1][j],dp[i - 1][j - 1],dp[i][j - 1] });

					dp[i][j] = max(dp[i][j], m + 1);
					answer = max(answer, dp[i][j]);
				}				
			}
		}
		cout << answer <<'\n';
	}
}