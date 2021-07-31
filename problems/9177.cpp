#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N;
string a, b, c;
int visit[201][201];

bool bfs(){
	queue<pair<int, int>> q;
	memset(visit, 0, sizeof(visit));
	q.push({ 0,0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int aIdx = q.front().first;
		int bIdx = q.front().second;

		if (aIdx + bIdx == c.length()) {
			return true;
		}

		if (aIdx < a.length() && a[aIdx] == c[aIdx + bIdx] && visit[aIdx + 1][bIdx] == 0) {
			q.push({ aIdx + 1,bIdx });
			visit[aIdx + 1][bIdx] = 1;
		}
		if (bIdx < b.length() && b[bIdx] == c[aIdx + bIdx] && visit[aIdx][bIdx + 1] == 0) {
			q.push({ aIdx,bIdx + 1 });
			visit[aIdx][bIdx + 1] = 1;
		}
		q.pop();
	}
	return false;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		if (bfs())
			cout << "Data set " << i << ": yes\n";
		else
			cout << "Data set " << i << ": no\n";
	}
}