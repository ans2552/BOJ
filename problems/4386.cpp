#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n;
pair<double, double> pos[100];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
int parent[100];

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
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		cin >> pos[i].first >> pos[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= j)
				continue;

			double distance = sqrt((pos[i].first - pos[j].first)*(pos[i].first - pos[j].first) + (pos[i].second - pos[j].second)*(pos[i].second - pos[j].second));
			pq.push({ distance,{i,j} });
		}
	}

	double answer = 0;
	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;

		if (Union(a, b)) {
			answer += pq.top().first;
		}
		pq.pop();
	}

	cout << answer;
}