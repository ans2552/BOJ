#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
int cnt[100001];
vector<int> edge[100001];

int func(int node) {
	if (cnt[node])
		return cnt[node];

	cnt[node] = 1;
	for (int next : edge[node]) {
		if (cnt[next] == 0)
			cnt[node] += func(next);
	}
	return cnt[node];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int u, v;
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	func(R);
	for (int i = 0; i < Q; i++) {
		cin >> u;
		cout << cnt[u] << '\n';
	}
}