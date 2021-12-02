#include <iostream>
using namespace std;

int n;
int arr[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int cow, pos;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		cin >> cow >> pos;
		if (arr[cow] == 0) {
			arr[cow] = pos + 1;
		}
		else if (arr[cow] != pos + 1) {
			answer++;
			arr[cow] = pos + 1;
		}
	}
	cout << answer;
}