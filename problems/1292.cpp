#include <iostream>
using namespace std;

int arr[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int now = 1;
	int cnt = 0;
	for (int i = 1; i <= 1000; i++) {
		arr[i] = now;
		cnt++;
		if (cnt == now) {
			now++;
			cnt = 0;
		}
	}

	int A, B;
	cin >> A >> B;

	int answer = 0;
	for (int i = A; i <= B; i++) {
		answer += arr[i];
	}
	cout << answer;
}