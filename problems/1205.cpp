#include <iostream>
using namespace std;

int N, P;
int score;
int ranking[50];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> score >> P;

	for (int i = 0; i < N; i++) {
		cin >> ranking[i];
	}

	int answer;
	if (N < P) {
		answer = N;
		for (int i = 0; i < N; i++) {
			if (score >= ranking[i]) {
				answer = i;
				break;
			}
		}
	}
	else {
		answer = -2;
		if (score != ranking[N - 1]) {
			for (int i = 0; i < N; i++) {
				if (score >= ranking[i]) {
					answer = i;
					break;
				}
			}
		}
	}
	cout << answer + 1;
}