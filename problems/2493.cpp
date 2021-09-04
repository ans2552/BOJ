#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[500001];
stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			s.pop();
		}
		if (s.empty())
			cout << "0 ";
		else
			cout << s.top() << ' ';
		s.push(i);
	}
}