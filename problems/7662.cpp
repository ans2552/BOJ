#include <iostream>
#include <set>
using namespace std;

int T, k, n;
char c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> k;
		multiset<int> ms;
		while (k--) {
			cin >> c >> n;
			if (c == 'I') {
				ms.insert(n);
			}
			else if (c == 'D') {
				if (ms.empty())
					continue;
				if (n == 1)
					ms.erase(--ms.end());
				else if (n == -1)
					ms.erase(ms.begin());
			}
		}
		if (ms.empty())
			cout << "EMPTY\n";
		else
			cout << *--ms.end() << ' ' << *ms.begin() << '\n';
	}
}