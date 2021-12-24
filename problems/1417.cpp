#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int me, t;
	cin >> N;
	cin >> me;

	for (int i = 1; i < N; i++) {
		cin >> t;
		pq.push(t);
	}

	int answer = 0;
	while (!pq.empty()) {
		t = pq.top();

		if (t < me) {
			break;
		}
		else {
			pq.pop();
			pq.push(t - 1);
			me++;
			answer++;
		}
	}
	cout << answer;
}