#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N;
bool check[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	string s;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		memset(check, 0, sizeof(check));
		bool isGroup = true;;
		for (int j = 0; j < s.length(); j++) {
			if (check[s[j] - 'a']) {
				if (s[j - 1] != s[j]) {
					isGroup = false;
				}
			}
			else {
				check[s[j] - 'a'] = true;
			}
		}
		if (isGroup)
			answer++;
	}
	cout << answer;
}