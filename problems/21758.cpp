#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int sum1[100000];
int sum2[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		sum1[i] = sum;
	}

	sum2[0] = sum;
	for (int i = 1; i < N; i++) {
		sum -= arr[i - 1];
		sum2[i] = sum;
	}

	int answer = 0;
	//벌통이 오른쪽 끝에 있는 경우
	int cnt = sum1[N - 1] - sum1[0];
	for (int i = 1; i < N - 1; i++) {
		answer = max(answer, cnt + sum1[N - 1] - sum1[i] - arr[i]);
	}

	//벌통이 왼쪽 끝에 있는 경우
	cnt = sum2[0] - sum2[N - 1];
	for (int i = N - 2; i > 0; i--) {
		answer = max(answer, cnt + sum2[0] - sum2[i] - arr[i]);
	}
	//벌통이 가운데 있는 경우
	for (int i = 1; i < N - 1; i++) {
		answer = max(answer, sum1[i] - sum1[0] + sum2[i] - sum2[N - 1]);
	}

	cout << answer;
}
