#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<pair<int, int>> v[101][101];
int light[101][101];
int visit[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int answer;
bool findLight;

bool isRange(int x, int y) {
	return x > 0 && y > 0 && x <= N && y <= N;
}

void bfs() {
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visit[1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (pair<int, int> p : v[x][y]) {
			int px = p.first;
			int py = p.second;

			if (light[px][py] == 0) {
				light[px][py] = 1;
				answer++;
				findLight = true;
			}			
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isRange(nx, ny) && visit[nx][ny] == 0 && light[nx][ny]==1) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}

		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b });
	}

	light[1][1] = 1;
	answer = 1;
	findLight = true;
	while (findLight) {
		findLight = false;
		bfs();
	}

	cout << answer;
}