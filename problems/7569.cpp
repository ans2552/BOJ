#include <iostream>
#include <queue>
using namespace std;

int arr[100][100][100];
int N, M, H;
struct Pos {
	int x;
	int y;
	int z;
};

int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

bool isRange(int x, int y, int z) {
	return x >= 0 && y >= 0 && z >= 0 && x < H && y < N&&z < M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;

	queue<Pos> q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i,j,k });
				}
			}
		}
	}

	int answer = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int cnt = arr[x][y][z];
		answer = max(answer, cnt);
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (isRange(nx, ny, nz) && arr[nx][ny][nz] == 0) {
				arr[nx][ny][nz] = cnt + 1;
				q.push({ nx,ny,nz });
			}
		}
	}

	answer--;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (arr[i][j][k] == 0) {
					answer = -1;
					break;
				}
			}
			if (answer == -1)
				break;
		}
		if (answer == -1)
			break;
	}
	cout << answer;
}