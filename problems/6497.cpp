#include <iostream>
#include <queue>
using namespace std;

int m, n;
int x, y, z;
int parent[200000];

int find_parent(int a) {
	if (a == parent[a])
		return a;

	return parent[a] = find_parent(parent[a]);
}

bool Union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa != pb) {
		parent[pa] = pb;
		return true;
	}
	return false;
}

struct Road {
	int x;
	int y;
	int z;
	
	bool operator < (const Road& rhs) const {
		return z > rhs.z;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		priority_queue<Road> pq;

		int answer = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			answer += z;
			pq.push({ x, y, z });
		}
		int cnt = 0;
		while (!pq.empty()) {
			Road t = pq.top();
			pq.pop();

			if (Union(t.x, t.y)) {
				answer -= t.z;
				cnt++;
			}
			if (cnt == m - 1)
				break;
		}
		cout << answer << '\n';
	}
}