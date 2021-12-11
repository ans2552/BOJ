#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int left = 1;
	int right = 1;
	int sum = 0;
	int answer = 0;
	while (left <= right && right <= N + 1) {
		if (sum > N) {
			sum -= left;
			left++;
		}
		else if (sum < N) {
			sum += right;
			right++;
		}
		else {
			answer++;
			sum += right;
			right++;
		}
	}
	cout << answer;
}