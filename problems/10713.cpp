#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int P[100000];
long long sum[100000];
int a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> P[i];
	}

	for (int i = 0; i < M - 1; i++) {
		if (P[i] < P[i + 1]) {
			sum[P[i]] += 1;
			sum[P[i + 1]] -= 1;
		}
		else {
			sum[P[i + 1]] += 1;
			sum[P[i]] -= 1;
		}
	}

	for (int i = 1; i < N; i++) {
		sum[i] += sum[i - 1];
	}

	long long answer = 0;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		answer += min(sum[i] * a, sum[i] * b + c);
	}
	cout << answer;
}
