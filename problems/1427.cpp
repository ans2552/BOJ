#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N > 0) {
		v.push_back(N % 10);
		N /= 10;
	}

	sort(v.begin(), v.end(), greater<int>());

	for (int i : v) {
		cout << i;
	}
}