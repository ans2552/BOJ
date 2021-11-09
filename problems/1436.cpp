#include <iostream>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int count = 0;
	int title = 665;
	while (title++) {
		string s = to_string(title);

		if (s.find("666") != -1) {
			count++;
		}

		if (count == n) {
			cout << title;
			break;
		}
	}
}