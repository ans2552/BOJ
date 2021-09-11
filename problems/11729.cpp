#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;

void hanoi(int i, int start, int end) {

	if (i == 1) {
		v.push_back({ start,end });
		return;
	}

	int mid = 6 - start - end;
	hanoi(i - 1, start, mid);
	v.push_back({ start, end });
	hanoi(i - 1, mid, end);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	hanoi(N, 1, 3);

	cout << v.size() << '\n';
	for (auto vv : v) {
		cout << vv.first << ' ' << vv.second << '\n';
	}
}