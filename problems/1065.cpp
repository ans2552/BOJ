#include <iostream>
using namespace std;

int N;
int answer;

bool hansoo(int x) {
    if (x < 100) return true;

    int a1, a2, a3;
    a3 = x / 100;
    a1 = x % 10;
    a2 = x % 100 / 10;
    if (a3 - a2 == a2 - a1) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (hansoo(i)) answer++;
    }
    cout << answer;
}