#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100000];

void binary_search(int x) {
	int start = 0;
	int end = N - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (A[mid] == x) {
			cout << "1\n";
			return;
		}
		else if (A[mid] > x) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << "0\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);
	cin >> M;
	int x;
	for (int i = 0; i < M; i++) {
		cin >> x;
		binary_search(x);
	}
}