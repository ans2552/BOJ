#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int N, K;
int visit[MAX + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N,0 });
	int time;
	int cnt = 0;
	while (!q.empty()) {
		int f = q.front().first;
		int t = q.front().second;

		q.pop();
		visit[f] = 1;

		if (cnt != 0 && f == K && t == time)
			cnt++;

		if (cnt == 0 && f == K) {
			time = t;
			cnt++;
		}

		if (f > 0) {
			if (visit[f - 1] == 0) {
				q.push({ f - 1 ,t + 1 });
			}
		}

		if (f < K) {
			if (visit[f + 1] == 0) {
				q.push({ f + 1 ,t + 1 });
			}
		}

		if (f <= MAX / 2) {
			if (visit[f * 2] == 0) {
				q.push({ f * 2, t + 1 });
			}
		}
	}
	cout << time << ' ' << cnt;
}