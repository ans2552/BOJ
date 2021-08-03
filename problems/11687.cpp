#include <iostream>

using namespace std;

int M;

int main() {
	cin >> M;

	int left = 0;
	int right = 500000000;

	bool isFind = false;
	int answer;
	while (left <= right) {
		int mid = (left + right) / 2;

		int cnt = 0;
		for (int i = 5; i <= mid; i *= 5) {
			cnt += mid / i;
		}

		if (cnt < M) {
			left = mid + 1;
		}
		else if (cnt > M) {
			right = mid - 1;
		}
		else {
			isFind = true;
			answer = mid;
			right = mid - 1;
		}
	}
	if (isFind)
		cout << answer;
	else
		cout << -1;
}
