#include <iostream>
#include <queue>
using namespace std;

int N, M;
int parent[100001];
priority_queue<pair<int, pair<int, int>>> pq;

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

	cin >> N >> M;
    	
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		pq.push({ C*-1,{A,B} });
	}

	int answer = 0;
	int sum = 0;
	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;

		if (Union(a, b)) {
			answer = sum;
			sum += pq.top().first * -1;
		}
		pq.pop();
	}
	cout << answer;
}