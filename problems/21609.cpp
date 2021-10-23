#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int arr[20][20];
int visit[20][20];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxCnt;
int maxMCnt;
int maxSX;
int maxSY;
int answer;
vector<pair<int, int>> del1;

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> del;

	int nVisit[20][20];
	memset(nVisit, 0, sizeof(nVisit));

	q.push({ x,y });
	del.push_back({ x,y });

	visit[x][y] = 1;
	nVisit[x][y] = 1;

	int now = arr[x][y];
	int cnt = 0;
	int mCnt = 0;

	int sx = 30;
	int sy = 30;


	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;

		if (fx < sx) {
			sx = fx;
			sy = fy;
		}
		else if (sx == fx) {
			if (fy < sy) {
				sx = fx;
				sy = fy;
			}
		}

		cnt++;
		if (arr[fx][fy] == 0)
			mCnt++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];

			if (isRange(nx, ny) && nVisit[nx][ny] == 0 && arr[nx][ny] != -1) {
				if (arr[nx][ny] == 0) {
					q.push({ nx,ny });
					del.push_back({ nx,ny });
					nVisit[nx][ny] = 1;
				}
				else if (arr[nx][ny] == now) {
					q.push({ nx,ny });
					del.push_back({ nx,ny });
					nVisit[nx][ny] = 1;
					visit[nx][ny] = 1;
				}
			}
		}
	}

	if (maxCnt < cnt) {
		maxCnt = cnt;
		maxMCnt = mCnt;
		del1 = del;
	}
	else if (maxCnt == cnt) {
		if (maxMCnt < mCnt) {
			maxCnt = cnt;
			maxMCnt = mCnt;
			del1 = del;
		}
		else if (maxMCnt == mCnt) {
			if (maxSX < sx || (maxSX == sx && maxSY < sy)) {
				maxCnt = cnt;
				maxMCnt = mCnt;
				del1 = del;
			}
		}
	}
}

void gravity() {
	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			if (arr[i][j] != -2)
				continue;
			int t = -1;
			for (int k = i - 1; k >= 0; k--) {
				if (arr[k][j] == -1)
					break;
				if (arr[k][j] >= 0) {
					t = k;
					break;
				}
			}
			if (t != -1) {
				arr[i][j] = arr[t][j];
				arr[t][j] = -2;
			}
		}
	}
}

void rotate() {

	int arr2[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr2[i][j] = arr[j][N - 1 - i];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		memset(visit, 0, sizeof(visit));
		maxCnt = 0;
		maxMCnt = 0;
		maxSX = -1;
		maxSY = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0 && arr[i][j] > 0) {
					bfs(i, j);
				}
			}
		}
		if (maxCnt < 2)
			break;
		answer += maxCnt * maxCnt;
		for (pair<int, int> p : del1) {
			arr[p.first][p.second] = -2;
		}

		gravity();
		rotate();
		gravity();
	}
	cout << answer;
}