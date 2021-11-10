#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int cnt[9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '6' || s[i] == '9') {
			cnt[6]++;
		}
		else
			cnt[s[i] - '0']++;
	}

	int ans = 0;
	for (int i = 0; i < 9; i++) {
		if (i == 6)
			ans = max(ans, (cnt[i] + 1) / 2);
		else
			ans = max(ans, cnt[i]);
	}
	cout << ans;
}