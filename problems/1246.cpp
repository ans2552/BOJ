#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int P[1000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> P[i];
	}
	sort(P, P + M);

	int result = 0;
	int total = 0;
	int price = 0;
	for (int i = 0; i < M; i++) {
		if (M - i < N)
			result = P[i] * (M - i);
		else
			result = P[i] * N;

		if (total < result) {
			price = P[i];
			total = result;
		}
	}
	cout << price << ' ' << total;
}