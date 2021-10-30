#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m1;
string m2[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, int> m1;
	map<int, string> m2;

	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		m1[s] = i;
		m2[i] = s;
	}

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			cout << m2[stoi(s)] << '\n';
		}
		else {
			cout << m1[s] << '\n';
		}
	}
}