#include <iostream>
#include <string>
#include <deque>
using namespace std;

int T;
string s;
int n;
string cmd;
string nums;
deque<int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> cmd >> n >> nums;
		dq.clear();
		string temp = "";
		int state = 1;
		for (int i = 0; i < nums.length(); i++) {
			if (nums[i] >= '0' && nums[i] <= '9') {
				temp += nums[i];
			}
			else if (temp != "") {
				dq.push_back(stoi(temp));
				temp = "";
			}
		}
		int flag = 0;
		for (int i = 0; i < cmd.length(); i++) {
			if (cmd[i] == 'R') {
				state *= -1;
			}
			else if (cmd[i] == 'D') {
				if (dq.empty()) {
					flag = 1;
					break;
				}
				if (state == 1) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}

		if (flag) {
			cout << "error\n";
		}
		else {
			cout << '[';
			for (int i = 0; i < dq.size(); i++) {
				if (state == 1) {
					cout << dq[i];
				}
				else {
					cout << dq[dq.size() - 1 - i];
				}

				if (i != dq.size() - 1) {
					cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}