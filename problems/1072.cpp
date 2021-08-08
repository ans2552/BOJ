#include <iostream>
using namespace std;

long long X, Y, Z;

int main() {
	cin >> X >> Y;
	Z =Y * 100 / X;

	int answer=0;
	if (Z == 99 || Z==100)
		cout << -1;
	else {
		int left = 0;
		int right = X;

		while (left <= right) {
			int mid = (left + right) / 2;

			int winRate = (Y + mid)*100 / (X +  mid);
			if (winRate == Z) {
				left = mid + 1;
			}
			else {
				answer = mid;
				right = mid - 1;
			}
		}

		cout << answer;
	}
}