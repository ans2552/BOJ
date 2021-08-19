#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T, N, M, K;
int dist[101][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> M >> K;

		vector<pair<int, pair<int, int>>> ticket[101];
		int u, v, c, d;
		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;
			ticket[u].push_back({ v,{c,d} });
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		memset(dist, 0x7f, sizeof(dist));

		pq.push({ 0,{0,1} });
		dist[1][0] = 0;

		while (!pq.empty()) {
			int day = pq.top().first * -1;
			int money = pq.top().second.first * -1;
			int node = pq.top().second.second;

			pq.pop();
			if (dist[node][money] < day)
				continue;

			if (node == N)
				break;

			for (auto next : ticket[node]) {
				if (money + next.second.first > M)
					continue;

				if (dist[next.first][money+next.second.first] > day + next.second.second ) {
					dist[next.first][money + next.second.first] = day + next.second.second;
					pq.push({ dist[next.first][money + next.second.first] *-1, {(money + next.second.first)*-1, next.first} });
				}
			}
		}
		
		int answer = 0x7f7f7f7f;
		for (int i = 0; i <= M; i++) {
			answer = min(answer, dist[N][i]);
		}
		if (answer != 0x7f7f7f7f)
			cout << answer << '\n';
		else
			cout << "Poor KCM\n";
	}
}