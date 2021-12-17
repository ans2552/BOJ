#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	int len = S.length();
	int idx = 0;
	bool check = true;
	string s;
	while (idx < len) {
		s = S.substr(idx, 2);
		if (s == "pi" || s == "ka") {
			idx += 2;
			continue;
		}
		else {
			s = S.substr(idx, 3);
			if (s == "chu") {
				idx += 3;
			}
			else {
				check = false;
				break;
			}
		}
	}
	if (check)
		cout << "YES";
	else
		cout << "NO";
}