#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
vector<string> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int len = s.length();
	for (int i = 1; i < len - 1; i++) {
		for (int j = 1; i + j < len; j++) {
			string first = s.substr(0, i);
			string second = s.substr(i, j);
			string third = s.substr(i + j);

			reverse(first.begin(), first.end());
			reverse(second.begin(), second.end());
			reverse(third.begin(), third.end());
			string ns = first + second + third;

			ans.push_back(ns);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0];
}