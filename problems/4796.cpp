#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 0;
	int L, P, V;
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;

		tc++;
		int t = min(V%P, L);
		int result = (V / P)*L + t;
		cout << "Case " << tc << ": " << result << '\n';
	}
}