#include <iostream>
#include <algorithm>
using namespace std;

int dist[100000];
int cost[100000];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	long long now = cost[0];
	long long total = now * dist[1];
	for (int i = 1; i < n; i++) {
		if (now < cost[i]) {
			total += now * dist[i + 1];
		}
		else {
			now = cost[i];
			total += now * dist[i + 1];
		}
	}
	cout << total;
}