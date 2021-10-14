#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
char arr[50][50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = answer; k < 50; k++) {
				int a = arr[i][j];
				if (i + k >= N)
					break;
				int b = arr[i + k][j];
				if (a != b)
					continue;

				if (j + k >= M)
					break;
				b = arr[i][j + k];
				if (a != b)
					continue;

				b = arr[i + k][j + k];
				if (a != b)
					continue;

				answer = max(answer, k);
			}
		}
	}
	cout << (answer + 1)*(answer + 1);
}