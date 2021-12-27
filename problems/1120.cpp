#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	int answer = 50;
	int al = A.length();
	int bl = B.length();
	for (int j = 0; j <= bl - al; j++) {
		int cnt = 0;
		for (int i = 0; i < A.length(); i++) {
			if (A[i] != B[i + j])
				cnt++;
		}
		answer = min(answer, cnt);
	}
	cout << answer;
}