#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
pair<int,int> cost[1001];
int A, B;

void dijkstra() {
	fill(cost, cost + 1001, make_pair(2000000000, 0));
	cost[A] = { 0, 0 };
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,A });
	while (!pq.empty()) {
		int val = pq.top().first * -1;
		int node = pq.top().second;
		pq.pop();

		if (val > cost[node].first)
			continue;

		for (auto next : v[node]) {
			if (cost[next.first].first > val + next.second) {
				cost[next.first].first = val + next.second;
				cost[next.first].second = node;
				pq.push({ cost[next.first].first * -1 , next.first });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int s, e, c;
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> c;
		v[s].push_back({ e,c });
	}
	cin >> A >> B;

	dijkstra();
	cout << cost[B].first << '\n';

	vector<int> answer;
	answer.push_back(B);

	int next = cost[B].second;
	while (next != 0) {
		answer.push_back(next);
		next = cost[next].second;
	}
	cout << answer.size() << '\n';
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << ' ';
	}
}