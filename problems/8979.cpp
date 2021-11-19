#include <iostream>
using namespace std;

int N, K;
int gold[1001];
int silver[1001];
int bronze[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cin >> gold[x] >> silver[x] >> bronze[x];
	}

	int ans = 1;
	for (int i = 1; i <= N; i++) {
		if (gold[i] > gold[K]) {
			ans++;
		}
		else if (gold[i] == gold[K]) {
			if (silver[i] > silver[K]) {
				ans++;
			}
			else if (silver[i] == silver[K]) {
				if (bronze[i] > bronze[K]) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}