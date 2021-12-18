#include <iostream>
#include <string>
using namespace std;

int N, K;
string s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> s;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] != 'P') 
            continue;

        for (int j = -K; j <= K; j++) {
            int idx = i + j;
            if (idx < 0 || idx > N) 
                continue;

            if (s[idx] == 'H') {
                ans++;
                s[idx] = 'C';
                break;
            }
        }
    }
    cout << ans;
}