#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while (1) {
		cin >> s;
		if (s == "0")
			break;
		string ans = "yes\n";
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - 1 - i]) {
				ans = "no\n";
				break;
			}
		}
		cout << ans;
	}
}