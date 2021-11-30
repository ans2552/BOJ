#include <iostream>
#include <string>
using namespace std;

string changeNum(string x) {
	int ret = 0;
	for (int i = 0; i < x.length(); i++) {
		ret += x[i] - '0';
	}

	return to_string(ret);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string n;
	cin >> n;

	int cnt = 0;
	while (n.length() != 1) {
		cnt++;
		n = changeNum(n);
	}
	cout << cnt << '\n';
	if (n == "3" || n == "6" || n == "9")
		cout << "YES";
	else
		cout << "NO";
}