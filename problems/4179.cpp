#include <iostream>
#include <queue>
using namespace std;

int R, C;
int arr[1001][1001];
int fire[1001][1001];
int visit[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> jh;
queue<pair<int, int>> q;

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < R && y < C;
}

void burn() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = fire[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny) && fire[nx][ny] == 0 && arr[nx][ny] == 0) {
				q.push({ nx,ny });
				fire[nx][ny] = cnt + 1;
			}
		}
		q.pop();
	}
}

int escape() {
	q.push(jh);
	visit[jh.first][jh.second] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int cnt = visit[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!isRange(nx, ny)) {
				return cnt;
			}
			if (visit[nx][ny] == 0 && arr[nx][ny] != 2 && (fire[nx][ny] == 0 || fire[nx][ny] - 1 > cnt)) {
				q.push({ nx,ny });
				visit[nx][ny] = cnt + 1;
			}
		}
		q.pop();
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	char t;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> t;
			if (t == '#') {
				arr[i][j] = 2;
			}
			else if (t == 'J')
				jh = { i,j };
			else if (t == 'F') {
				q.push({ i,j });
				fire[i][j] = 1;
			}
		}
	}
	burn();
	int answer = escape();
	if (answer == -1)
		cout << "IMPOSSIBLE";
	else
		cout << answer;
}