#include <iostream>
#include <cmath>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int cnt = 0;
	int temp = N;
	while (temp > 0) {
		temp /= 10;
		cnt++;
	}

	int answer = 0;
	for (int i = 1; i < cnt; i++) {
		answer += i * (pow(10, i) - pow(10, i - 1));
	}
	answer += cnt * (N - pow(10, cnt - 1) + 1);
	cout << answer;
}