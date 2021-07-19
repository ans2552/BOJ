#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000000

using namespace std;

int T, N, A, B;
int prime[MAX + 1];
int visit[MAX + 1];

int bfs() {
	queue<int> q;
	q.push(N);
	visit[N] = 1;

	while (!q.empty()) {
		int front = q.front();
		int cnt = visit[front];

		if (A <= front && front <= B && prime[front] == 0) {
			return cnt - 1;
		}

		if (visit[front / 2] == 0) {
			q.push(front / 2);
			visit[front / 2] = cnt + 1;
		}
		if (visit[front / 3] == 0) {
			q.push(front / 3);
			visit[front / 3] = cnt + 1;
		}
		if (front < B && visit[front+1]==0) {
			q.push(front + 1);
			visit[front + 1] = cnt + 1;
		}
		if (front > 0 && visit[front - 1] == 0) {
			q.push(front - 1);
			visit[front - 1] = cnt + 1;
		}
		q.pop();
	}
	return -1;
}

int main(){
	prime[1] = 1;
	for (int i = 2; i*i <= MAX; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = 1;
			}
		}
	}

	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		memset(visit, 0, sizeof(visit));
		cout << bfs() << '\n';
	}
}