#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
int avg;
int maxCnt;
int maxV;
vector<int> v;
int cnt[8001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
		avg += x;

		int temp = (v[i] <= 0) ? abs(v[i]) : v[i] + 4000;
		cnt[temp]++;
		if (cnt[temp] > maxCnt)
			maxCnt = cnt[temp];
	}
	sort(v.begin(), v.end());

	bool isSecond = false;
	for (int i = -4000; i < 4001; i++) {
		int temp = i <= 0 ? abs(i) : i + 4000;
		if (cnt[temp] == maxCnt) {
			maxV = i;
			if (isSecond)
				break;
			isSecond = true;
		}
	}

	cout << round(avg / (double)N) << '\n';
	cout << v[N / 2] << '\n';
	cout << maxV << '\n';
	cout << v[N - 1] - v[0] << '\n';
}