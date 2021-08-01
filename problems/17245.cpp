#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	long long totalCnt = 0;
	int maxHeight = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			totalCnt += arr[i][j];
			if (maxHeight < arr[i][j])
				maxHeight = arr[i][j];
		}
	}
	if (totalCnt % 2)
		totalCnt++;

	int left = 0;
	while (1) {
		if (left == maxHeight)
			break;

		int mid = (left + maxHeight) / 2;
		long long nowCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				nowCnt += min(mid, arr[i][j]);
			}
		}
		if (nowCnt >= totalCnt / 2) {
			maxHeight = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << maxHeight;
}