#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N;
string s;
map<char, int> m;
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> s;
	int left = 0;
	int right = 0;
	int answer = 0;
	while (right < s.length()) {
		if (cnt <= N) {
			m[s[right]]++;
			if (m[s[right]] == 1) {
				cnt++;
			}
			right++;
			if (cnt <= N) {
				answer = max(answer, right - left);
			}
		}
		else {
			m[s[left]]--;
			if (m[s[left]] == 0) {
				cnt--;
			}
			left++;
		}
	}
	cout << answer;
}