#include <iostream>
#include <string>
#include <set>

using namespace std;

int n;
string name, type;
set<string> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		cin >> name >> type;

		if (type == "enter") {
			st.insert(name);
		}
		else {
			st.erase(name);
		}
	}

	for (auto it = st.rbegin(); it != st.rend(); it++) {
		cout << *it << '\n';
	}
}