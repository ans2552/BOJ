#include <iostream>
using namespace std;

int arr[2][9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 9; i++) {
			cin >> arr[j][i];
		}
	}

	int score1 = 0;
	int score2 = 0;
	int check = false;
	for (int i = 0; i < 9; i++) {
		score1 += arr[0][i];
		if (score1 > score2) {
			check = true;
			break;
		}
		score2 += arr[1][i];
	}

	if (check)
		cout << "Yes";
	else
		cout << "No";
}