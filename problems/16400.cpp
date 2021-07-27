#include <iostream>
#include <vector>
using namespace std;

int N;
long long dp[40001];
int primeCheck[40001];
vector<int> prime;

int main() {
	cin >> N;

	primeCheck[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (primeCheck[i] == 0) {
			prime.push_back(i);
			for (int j = i*i; j <= N; j += i) {
				primeCheck[j] = 1;
			}
		}
	}

	dp[0] = 1;
	for (int p : prime) {
		for (int i = p; i <= N; i++) {
			dp[i] = (dp[i] + dp[i - p]) % 123456789;
		}
	}
	cout << dp[N];
}