#include <iostream>
using namespace std;

int n, m;
int parent[500000];

int find(int a) {
	int pa = parent[a];
	if (pa == a)
		return a;

	return parent[a] = find(pa);
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa != pb) {
		parent[pa] = pb;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (!Union(a,b)) {
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
}