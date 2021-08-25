#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[1000001];
vector<int> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << dp.size();
}