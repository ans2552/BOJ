#include <iostream>
using namespace std;

int check[42];
int main() {
	int num;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		check[num % 42]++;
	}

	int answer = 0;
	for (int i = 0; i < 42; i++) {
		if (check[i] > 0)
			answer++;
	}
	cout << answer;
}