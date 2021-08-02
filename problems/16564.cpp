#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int level[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> level[i];
	};

	sort(level, level + N);

	int left = level[0];
	int right = level[0] + K;

	int answer = 0;
	while (left <= right) {
		int mid = ((long long)left + right) / 2;
		
		long long need = 0;
		for (int i = 0; i < N; i++) {
			if (mid > level[i])
				need += mid - level[i];
			else
				break;
		}
		
		if (need > K) {
			right = mid - 1;
		}
		else {
			answer = mid;
			left = mid + 1;
		}
	}
	cout << answer;
}