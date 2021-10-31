#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int type = 0;
	while (q.size() > 1) {
		if (type == 0) {
			q.pop();
			type = 1;
		}
		else {
			int f = q.front();
			q.pop();
			q.push(f);
			type = 0;
		}
	}
	cout << q.front();
}