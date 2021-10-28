#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> s;
int main()
{
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}

	int answer = 0;
	for (int i = 0; !s.empty(); i++) {
		answer += s.top();
		s.pop();
	}

	cout << answer;
}