#include <iostream>
using namespace std;

int arr[5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				for (int k = 0; k < 5; k++) {
					cout << arr[k] << " ";
				}
				cout << '\n';
			}
		}
	}
}