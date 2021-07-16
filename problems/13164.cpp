#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[300000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int prev, now;
	cin >> prev;
	for (int i = 0; i < N - 1; i++) {
		cin >> now;
		arr[i] = now - prev;
		prev = now;
	}

	sort(arr, arr + N - 1);
	int answer = 0;
	for (int i = 0; i < N - K; i++) {
		answer += arr[i];
	}
	cout << answer;	
}