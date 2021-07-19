#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 0x0f0f0f0f
using namespace std;

int N, M;
int check[10001];
int dp[10001][150];

int func(int i, int j) {
	if (j <= 0 || j >= 150 || i <= 0 || check[i])
		return MAX;

	if (dp[i][j] != MAX)
		return dp[i][j];

	return dp[i][j] = min({ func(i - j,j),func(i - j,j + 1), func(i - j,j - 1) }) + 1;
}


int main(){
	cin >>  N >> M;
	int t;
	for (int i = 0; i < M; i++) {
		cin >> t;
		check[t] = 1;
	}

	memset(dp, 0x0f, sizeof(dp));
	int answer = MAX;
	dp[2][1] = 1;
	for (int i = 1; i < 150; i++) {
		answer = min(answer, func(N,i));
	}
	if (answer == MAX)
		cout << -1;
	else
		cout << answer;	

}