#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000][5];
int score[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				for (int l = k + 1; l < 5; l++) {
					score[i] = max(score[i], (arr[i][j] + arr[i][k] + arr[i][l]) % 10);
				}
			}
		}
	}

	int answer = 0;
	int maxNum = 0;
	for (int i = 0; i < N; i++) {
		if (maxNum <= score[i]) {
			answer = i;
			maxNum = score[i];
		}
	}
	cout << answer + 1;
}