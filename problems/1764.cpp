#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

int N, M;
set<string> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		s.insert(name);
	}
	vector<string> answers;
	for (int i = 0; i < M; i++) {
		cin >> name;
		if (s.find(name) != s.end()) {
			answers.push_back(name);
		}
	}

	sort(answers.begin(), answers.end());

	cout << answers.size() << '\n';
	for (string ans : answers) {
		cout << ans << '\n';
	}
}