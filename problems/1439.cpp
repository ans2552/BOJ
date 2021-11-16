#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int zero;
int one;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	if (s[0] == '0')
		zero++;
	else
		one++;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			if (s[i] == '0')
				zero++;
			else
				one++;
		}
	}
	cout << min(zero, one);
}