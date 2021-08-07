#include <iostream>
using namespace std;

int N, r, c;

int func(int n, int x, int y) {
    if (n == 1) {
        if (x == 0 && y == 0)
            return 0;
        else if (x == 0)
            return 1;
        else if (y == 0)
            return 2;
        else
            return 3;
    }

    if (x < 1 << (n - 1) && y < 1 << (n - 1)) {
        return func(n - 1, x, y);
    } else if (x < 1 << (n - 1)) {
        return (1 << (2 * n - 2)) + func(n - 1, x, y - (1 << (n - 1)));
    } else if (y < 1 << (n - 1)) {
        return (1 << (2 * n - 2)) * 2 + func(n - 1, x - (1 << (n - 1)), y);
    } else {
        return (1 << (2 * n - 2)) * 3 +
               func(n - 1, x - (1 << (n - 1)), y - (1 << (n - 1)));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> r >> c;
    cout << func(N, r, c);
}
