#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[50];
int B[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[N - 1 - i];
	}
	cout << answer;
}