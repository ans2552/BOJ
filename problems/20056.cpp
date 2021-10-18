#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;

struct Fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
};

queue<Fireball> q;
int dx[8] = { -1,-1, 0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

vector<Fireball> v[51][51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		Fireball info;
		cin >> info.r >> info.c >> info.m >> info.s >> info.d;
		q.push(info);
	}

	while (K--) {
		while (!q.empty()) {
			Fireball info = q.front();
			q.pop();

			int nr = info.r + dx[info.d] * info.s;
			int nc = info.c + dy[info.d] * info.s;

			if (nr > N) {
				nr = (nr - 1) % N + 1;
			}
			else if (nr <= 0) {
				nr = N - abs(nr) % N;
			}

			if (nc > N) {
				nc = (nc - 1) % N + 1;
			}
			else if (nc <= 0)
				nc = N - abs(nc) % N;

			info.r = nr;
			info.c = nc;

			v[nr][nc].push_back(info);
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (v[i][j].size() == 0)
					continue;

				int cnt = 0;
				int m = 0;
				int velocity = 0;
				bool isSame = true;
				int d = 0;
				for (Fireball node : v[i][j]) {
					cnt++;
					m += node.m;
					velocity += node.s;
					if (node.d % 2 == 0) {
						if (d == 2)
							isSame = false;
						d = 1;
					}
					else {
						if (d == 1)
							isSame = false;
						d = 2;
					}
				}

				//2개이상일때
				if (cnt > 1) {
					if (m / 5 == 0) {
						v[i][j].clear();
						continue;
					}

					for (int l = 0; l < 4; l++) {
						Fireball nf;
						nf.r = i;
						nf.c = j;
						nf.m = m / 5;
						nf.s = velocity / cnt;
						if (isSame)
							nf.d = 2 * l;
						else
							nf.d = 2 * l + 1;

						q.push(nf);
					}
				}
				//1개일때
				else {
					q.push(v[i][j].front());
				}
				v[i][j].clear();
			}
		}
	}

	int answer = 0;
	while (!q.empty()) {
		Fireball info = q.front();
		q.pop();
		answer += info.m;
	}

	cout << answer;
}