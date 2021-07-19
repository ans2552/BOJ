#include <iostream>
#include <algorithm>
using namespace std;

int b1, b2, b3;
int k1, k2;
int dp[501][501];//A가 지면 0 이기면 1

int main(){
	cin >> b1 >> b2 >> b3;
	int t = 5;
	while (t--) {
		cin >> k1 >> k2;
		for (int i = 0; i <= k1; i++) {
			for (int j = 0; j <= k2; j++) {
				dp[i][j] = 1;
				if (i >= b3) {
					dp[i][j] = min({ dp[i][j], dp[i - b1][j],dp[i - b2][j],dp[i - b3][j] });
				}
				else if (i >= b2) {
					dp[i][j] = min({ dp[i][j], dp[i - b1][j],dp[i - b2][j] });
				}
				else if (i >= b1) {
					dp[i][j] = min(dp[i][j], dp[i - b1][j]);
				}

				if (j >= b3) {
					dp[i][j] = min({ dp[i][j], dp[i][j - b1],dp[i][j - b2],dp[i][j - b3] });
				}
				else if (j >= b2) {
					dp[i][j] = min({ dp[i][j], dp[i][j - b1],dp[i][j - b2] });
				}
				else if (j >= b1) {
					dp[i][j] = min(dp[i][j], dp[i][j - b1]);
				}

				if (dp[i][j] == 0)
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
		}

		if (dp[k1][k2])
			cout << 'A' << '\n';
		else
			cout << 'B' << '\n';
	}
}