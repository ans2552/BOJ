#include <iostream>
using namespace std;

int N;
int prime[1001];

int main() {
	ios::sync_with_stdio(0);

	prime[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		if (prime[i] == 0) {
			for (int j = i + i; j <= 1000; j += i) {
				prime[j] = 1;
			}
		}
	}

	cin >> N;
	int x;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (prime[x] == 0)
			answer++;
	}
	cout << answer;
}