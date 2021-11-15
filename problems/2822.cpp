#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int score = 0;
	vector<pair<int, int>> v1;
	vector<int> v2;

	int a;
	for (int i = 0; i < 8; i++) {
		cin >> a;
		v1.push_back({ a,i + 1 });
	}
	sort(v1.begin(), v1.end());
	for (int i = 7; i >= 3; i--) {
		score += v1[i].first;
	}

	cout << score << "\n";
	int j = 0;
	for (int i = 7; i >= 3; i--) {
		v2.push_back(v1[i].second);
		sort(v2.begin(), v2.end());
	}

	for (int i = 0; i < 5; i++) {
		cout << v2[i] << " ";
	}
}