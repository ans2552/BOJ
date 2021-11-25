#include <iostream>
#include <string>
using namespace std;

char nextChar[4] = { 'U','C','P','C' };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);

	int idx = 0;
	for (char c : s) {
		if (nextChar[idx] == c) {
			idx++;
		}
		if (idx == 4)
			break;
	}

	if (idx == 4)
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";
}