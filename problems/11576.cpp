#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int A, B;
int m;
int decNum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	cin >> m;

	int num;
	while (m--) {
		cin >> num;
		decNum += num * pow(A, m);
	}

	vector<int> ans;
	while (decNum) {
		ans.push_back(decNum % B);
		decNum /= B;
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
}