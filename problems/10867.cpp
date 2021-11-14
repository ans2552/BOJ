#include <iostream>
#include <set>
using namespace std;

int N;
set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		s.insert(x);
	}

	for (int x : s) {
		cout << x << ' ';
	}
}