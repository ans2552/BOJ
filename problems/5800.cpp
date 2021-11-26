#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
int arr[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	int t = 0;
	while (t < K) {
		t++;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		int maxScore = arr[N - 1];
		int minScore = arr[0];
		int gap = 0;
		for (int i = 1; i < N; i++) {
			gap = max(gap, arr[i] - arr[i - 1]);
		}

		cout << "Class " << t << '\n';
		cout << "Max " << maxScore << ", Min " << minScore << ", Largest gap " << gap << '\n';
	}
}