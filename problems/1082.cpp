#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[51];
int N;
int cost[10];
int money;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}
	cin >> money;

	for (int i = 1; i <= money; i++) {
		for (int j = 0; j < N; j++) {
			if (i - cost[j] < 0)
				continue;

			for (int k = 0; k < dp[i - cost[j]].length(); k++) {
				if (dp[i - cost[j]][k] - '0' < j) {
					string t = dp[i - cost[j]].substr(0, k) + to_string(j) + dp[i - cost[j]].substr(k + 1);
					if (dp[i].length() < t.length())
						dp[i] = t;
					else if (dp[i].length() == t.length())
						dp[i] = max(dp[i], t);
				}
			}
			if (dp[i - cost[j]].empty() && j == 0)
				continue;

			string t = dp[i - cost[j]] + to_string(j);
			if (dp[i].length() < t.length())
				dp[i] = t;
			else if (dp[i].length() == t.length())
				dp[i] = max(dp[i], t);
		}
	}
	if (dp[money].empty())
		cout << 0;
	else
		cout << dp[money];
}
