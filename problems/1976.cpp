#include <iostream>
using namespace std;

int N, M;
int city[201][201];
int parent[201];

int find_parent(int a) {
	if (parent[a] == a)
		return a;

	return parent[a] = find_parent(parent[a]);
}

void Union(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa != pb) {
		parent[pa] = pb;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> city[i][j];
			if (city[i][j]) {
				Union(i, j);
			}
		}
	}

	int now = 0;
	int prev = 0;
	cin >> prev;
	for (int i = 1; i < M; i++) {
		cin >> now;
		if (find_parent(now) != find_parent(prev)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}