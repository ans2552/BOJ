#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[50][50];

int main() {
	cin >> N >> M;
	char t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> t;
			if (t == 'B')
				arr[i][j] = 1;
		}
	}

	int answer = 64;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int cnt = 0;
			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					if (arr[i + x][j + y] == (x + y) % 2) {
						cnt++;
					}
				}
			}
			if (cnt > 32) {
				cnt = 64 - cnt;
			}
			answer = min(answer, cnt);
		}
	}
	cout << answer;
}