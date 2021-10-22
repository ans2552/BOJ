#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<string> v;
	map<string, int> m;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if (m[s] == 0) {
			v.push_back(s);
			m[s] = 1;
		}
	}

	sort(v.begin(), v.end(), [](string a, string b) {
		if (a.length() == b.length()) {
			return a < b;
		}
		else
			return a.length() < b.length();

	});

	for (string ss : v) {
		cout << ss << '\n';
	}
}