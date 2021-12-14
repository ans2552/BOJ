#include <iostream>
#include <vector>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int num;
		cin >> num;
		bool check = true;
		for (int b = 2; b <= 64; b++) {
			int temp = num;
			check = true;

			vector<int> s;
			while (temp) {
				s.push_back(temp%b);
				temp /= b;
			}

			int len = s.size();
			for (int i = 0; i < len / 2; i++) {
				if (s[i] != s[len - 1 - i]) {
					check = false;
					break;
				}
			}
			if (check)
				break;
		}

		if (check)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}