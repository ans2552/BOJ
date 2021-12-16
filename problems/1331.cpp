#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string now;
	string prev;
	string first;
	set<string> s;
	bool valid = true;
	for (int i = 0; i <= 36; i++) {
		if (i == 36) {
			now = first;
		}
		else {
			cin >> now;
			if (s.find(now) != s.end()) {
				valid = false;
			}
			s.insert(now);
		}

		if (i == 0) {
			first = now;
		}
		else {
			if (!(abs(now[0] - prev[0]) == 1 && abs(now[1] - prev[1]) == 2) && !(abs(now[0] - prev[0]) == 2 && abs(now[1] - prev[1]) == 1)) {
				valid = false;
			}
		}
		prev = now;
	}

	if (valid)
		cout << "Valid";
	else
		cout << "Invalid";
}