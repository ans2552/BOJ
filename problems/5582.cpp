#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[4001][4001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2;

	int answer = 0;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer;
}