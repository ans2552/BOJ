#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> assignment[1000000]; // <마감기한, 걸리는시간>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> assignment[i].second >> assignment[i].first;
	}

	sort(assignment, assignment + n, greater<pair<int, int>>());

	int answer = 1000000000;
	for (int i = 0; i < n; i++) {
		if (answer > assignment[i].first)
			answer = assignment[i].first;

		answer -= assignment[i].second;
	}
	cout << answer;
}