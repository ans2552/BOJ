#include <iostream>
#include <string>
using namespace std;

int N;
string s;
string ring;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; i++) {
		cin >> ring;

		bool flag = false;
		for (int j = 0; j < ring.length(); j++) {
			if (ring[j] == s[0]) {
				flag = true;
				for (int k = 0; k < s.length(); k++) {
					if (ring[(j + k) % ring.length()] != s[k]) {
						flag = false;
						break;
					}
				}
				if (flag)
					break;
			}
		}
		if (flag)
			result++;
	}
	cout << result;
}