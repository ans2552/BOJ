#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
int arr[100][100];
int visit[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer;
int island_cnt = 1;

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

void set_island(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	arr[i][j] = island_cnt;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (isRange(nx, ny) && arr[nx][ny] == 1){ 
				if (arr[nx][ny] == 1) {
					q.push({ nx, ny });
					arr[nx][ny] = island_cnt;
				}
			}
		}
		q.pop();
	}
}

void make_bridge(int i, int j) {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = 1;
	int island_num = arr[i][j];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = visit[x][y];

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (isRange(nx, ny) && visit[nx][ny] == 0) {
				if (arr[nx][ny] == 0) {
					q.push({ nx, ny });
					visit[nx][ny] = cnt + 1;
				}
				else if (arr[nx][ny] != island_num) {
					answer = min(answer, cnt - 1);
					return;
				}
			}
		}
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				island_cnt++;
				set_island(i, j);
			}
		}
	}

	answer = 100000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 0)
				make_bridge(i, j);
		}
	}
	cout << answer;	
}