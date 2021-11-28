#include <iostream>
#include <algorithm>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int start = 0;
	int num = 0;
	int pre, now;

	for (int i = N / 2; i <= N; i++) {
		int pre = N;
		int now = i;
		int cnt = 0;
		while (pre >= 0) {
			int temp = now;
			now = pre - now;
			pre = temp;
			cnt++;
		}

		if (num < cnt) {
			num = cnt;
			start = i;
		}
	}

	cout << num << '\n';
	pre = N;
	now = start;
	while (pre >= 0) {
		cout << pre << ' ';
		int temp = now;
		now = pre - now;
		pre = temp;
	}
}