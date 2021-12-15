#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word;
	while (1) {
		cin >> word;
		if (word == "end")
			break;

		bool accept = true;
		bool check = false;
		int cnt1 = 0;
		int cnt2 = 0;
		char prev;
		for (int i = 0; i < word.length(); i++) {
			if (isVowel(word[i])) {
				cnt2 = 0;
				check = true;
				cnt1++;
				if (cnt1 >= 3) {
					accept = false;
					break;
				}
			}
			else {
				cnt1 = 0;
				cnt2++;
				if (cnt2 >= 3) {
					accept = false;
					break;
				}
			}
			if (i != 0) {
				if (word[i] == prev) {
					if (word[i] == 'e' || word[i] == 'o')
						continue;
					accept = false;
					break;
				}
			}
			prev = word[i];
		}

		if (accept && check)
			cout << '<' << word << "> is acceptable.\n";
		else
			cout << '<' << word << "> is not acceptable.\n";
	}
}