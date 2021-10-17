#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[20][20];
int check[401][401];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

int cntLike(int x, int y, int me) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isRange(nx, ny)) {
			int v = arr[nx][ny];
			if (check[me][v])
				ret++;
		}
	}
	return ret;
}

int cntVoid(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isRange(nx, ny) && arr[nx][ny]==0) {
			ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int k = 0; k < N*N; k++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		check[a][b] = 1;
		check[a][c] = 1;
		check[a][d] = 1;
		check[a][e] = 1;

		int cX = 0;
		int cY = 0;
		int cL = -1;
		int cV = -1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0)
					continue;
				int nL = cntLike(i, j, a);
				int nV = cntVoid(i, j);
				if (nL > cL) {
					cX = i;
					cY = j;
					cL = nL;
					cV = nV;
				}
				else if (nL == cL) {
					if (nV > cV) {
						cX = i;
						cY = j;
						cL = nL;
						cV = nV;
					}
				}
			}
		}
		arr[cX][cY] = a;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int me = arr[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (isRange(nx, ny)) {
					int  v = arr[nx][ny];
					if (check[me][v] == 1)
						cnt++;
				}
			}
			answer += int(pow(10, cnt - 1));

		}
	}
	cout << answer;

}