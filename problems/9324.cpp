#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cnt[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	string s;
	cin >> n;

	while (n--) {
		memset(cnt, 0, sizeof(cnt));
		string answer;
		cin >> s;
		bool check = true;

		for (int i = 0; i < s.length(); i++) {
			cnt[s[i] - 'A']++;
			if (cnt[s[i] - 'A'] == 3) {
				if (i == s.length() - 1 || s[i + 1] != s[i]) {
					check = false;
					break;
				}
				i++;
				cnt[s[i] - 'A'] = 0;
			}
		}
		if (check)
			cout << "OK\n";
		else
			cout << "FAKE\n";
	}
}