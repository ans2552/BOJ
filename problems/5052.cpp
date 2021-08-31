#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> hashSet;
string s;
int t, n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        hashSet.clear();

        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> s;
            hashSet.insert(s);
        }
        for (string str : hashSet) {
            if (flag) break;
            for (int j = 1; j < str.length(); j++) {
                string temp = str.substr(0, j);
                if (hashSet.find(temp) != hashSet.end()) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
