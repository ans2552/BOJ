#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + 10);

		cout << arr[7] << '\n';
	}
}