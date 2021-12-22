#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	string s;
	cin >> n;

	while (n--) {
		int cnt = 0;
		int answer = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				cnt++;
				answer += cnt;
			}
			else {
				cnt = 0;
			}
		}
		cout << answer << '\n';
	}
}