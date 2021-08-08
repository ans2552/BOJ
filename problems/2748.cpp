#include <iostream>

using namespace std;

long long fibo[91];
int n;

int main() {
	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n];
}