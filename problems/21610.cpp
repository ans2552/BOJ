#include <iostream>
#include <queue>
using namespace std;

int N, M, d, s;
int arr[51][51];
int dx[9] = { 0, 0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0, -1,-1,0,1,1,1,0,-1 };

int dx2[4] = { 1,1,-1,-1 };
int dy2[4] = { -1,1,1,-1 };
int visit[51][51];

bool isRange(int x, int y) {
	return x > 0 && y > 0 && x <= N && y <= N;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	queue<pair<int, int>> cloud;
	queue<pair<int, int>> q;

	cloud.push({ N,1 });
	cloud.push({ N,2 });
	cloud.push({ N - 1,1 });
	cloud.push({ N - 1,2 });

	while (M--) {
		cin >> d >> s;

		while (!cloud.empty()) {
			int x = cloud.front().first;
			int y = cloud.front().second;
			cloud.pop();

			x += dx[d] * s;
			y += dy[d] * s;

			if (x > N)
				x = (x - 1) % N + 1;
			else if (x <= 0)
				x = N - abs(x) % N;

			if (y > N)
				y = (y - 1) % N + 1;
			else if (y <= 0)
				y = N - abs(y) % N;

			q.push({ x,y });
			arr[x][y]++;
		}

		//물복사
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			visit[x][y] = 1;
			q.pop();
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx2[i];
				int ny = y + dy2[i];

				if (isRange(nx, ny) && arr[nx][ny] > 0)
					cnt++;
			}

			arr[x][y] += cnt;
		}

		//구름생성
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] >= 2 && visit[i][j] == 0) {
					cloud.push({ i,j });
					arr[i][j] -= 2;
				}
				visit[i][j] = 0;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += arr[i][j];
		}
	}
	cout << answer;
}