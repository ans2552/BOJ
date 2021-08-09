#include <iostream>
using namespace std;

int N, M, H;
int arr[31][11];
int answer;
int maxCnt;

bool check() {
	for (int i = 1; i <= N; i++) {
		int now = i;
		for (int j = 1; j <= H; j++) {
			if (arr[j][now] == 1) {
				now = now + 1;
			}
			else if (arr[j][now - 1] == 1) {
				now = now - 1;
			}
		}
		if (now != i)
			return false;
	}
	return true;
}

void dfs(int cnt, int y) {
	if (answer != -1) {
		return;
	}

	if (cnt == maxCnt) {
		if (check())
			answer = cnt;
		return;
	}

	for (int j = y; j <= H; j++) {
		for (int i = 1; i < N; i++) {
			if (arr[j][i] == 0 && arr[j][i - 1] == 0 && arr[j][i + 1] == 0) {
				arr[j][i] = 1;
				dfs(cnt + 1, j);
				arr[j][i] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}

	answer = -1;
	while (maxCnt <= 3) {
		dfs(0, 1);
		if (answer != -1)
			break;
		maxCnt++;
	}
	cout << answer;
}