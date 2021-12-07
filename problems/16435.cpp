#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int h[1000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	sort(h, h + N);

	for (int i = 0; i < N; i++) {
		if (h[i] <= L) {
			L++;
		}
		else {
			break;
		}
	}
	cout << L;
}