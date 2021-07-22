#include <iostream>
#include <deque>
using namespace std;

int N, L;
int arr[5000000];
deque<pair<int,int>> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().first >= arr[i]) {
			dq.pop_back();
		}

		dq.push_back({ arr[i],i });
		cout << dq.front().first << ' ';
	}
}