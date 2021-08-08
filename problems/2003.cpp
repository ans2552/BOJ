#include <iostream>

using namespace std;

int N, M;
int A[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int answer = 0;

	int left = 0;
	int right = 0;
	int sum = A[0];
	while (right < N) {
		if (sum < M) {
			right++;
			sum += A[right];
		}
		else if (sum > M) {
			sum -= A[left];
			left++;
		}
		else {
			answer++;
			right++;
			sum += A[right];
		}
	}

	cout << answer;
}