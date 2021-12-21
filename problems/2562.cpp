#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int maxV = 0;
	int idx = 0;
	int n;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (n > maxV) {
			maxV = n;
			idx = i;
		}
	}
	cout << maxV << '\n' << idx + 1;
}