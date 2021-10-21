#include <iostream>
using namespace std;

int N;
int arr[499][499];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int answer;

bool isRange(int x, int y) { return x >= 0 && y >= 0 && x < N && y < N; }

void sandMove(int x, int y, int amount) {
    if (isRange(x, y))
        arr[x][y] += amount;
    else
        answer += amount;
}

void func(int x, int y, int dir) {
    int sand = arr[x][y];
    int total = 0;
    int amount;

    int nx = x + dx[dir] * 2;
    int ny = y + dy[dir] * 2;
    amount = sand * 5 / 100;

    sandMove(nx, ny, amount);
    total += amount;

    //위
    int nDir = (dir + 3) % 4;
    nx = x + dx[nDir];
    ny = y + dy[nDir];
    amount = sand * 7 / 100;

    sandMove(nx, ny, amount);
    total += amount;

    amount = sand * 2 / 100;
    sandMove(nx + dx[nDir], ny + dy[nDir], amount);
    total += amount;

    nDir = (nDir + 1) % 4;
    amount = sand * 10 / 100;
    sandMove(nx + dx[nDir], ny + dy[nDir], amount);
    total += amount;

    nDir = (nDir + 2) % 4;
    amount = sand * 1 / 100;
    sandMove(nx + dx[nDir], ny + dy[nDir], amount);
    total += amount;

    //아래
    nDir = (dir + 1) % 4;
    nx = x + dx[nDir];
    ny = y + dy[nDir];
    amount = sand * 7 / 100;

    sandMove(nx, ny, amount);
    total += amount;

    amount = sand * 2 / 100;
    sandMove(nx + dx[nDir], ny + dy[nDir], amount);
    total += amount;

    nDir = (nDir + 1) % 4;
    amount = sand * 1 / 100;
    sandMove(nx + dx[nDir], ny + dy[nDir], amount);
    total += amount;

    nDir = (nDir + 2) % 4;
    amount = sand * 10 / 100;
    sandMove(nx + dx[nDir], ny + dy[nDir], amount);
    total += amount;

    sandMove(x + dx[dir], y + dy[dir], arr[x][y] - total);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int t = 2;
    int cnt = 1;
    int dir = 0;
    int x = N / 2;
    int y = N / 2;
    bool isBreak = false;
    while (cnt <= N) {
        if (cnt == N) {
            cnt--;
            isBreak = true;
        }

        for (int i = 0; i < cnt; i++) {
            x = x + dx[dir];
            y = y + dy[dir];
            func(x, y, dir);
        }

        if (isBreak) break;
        //다하고
        t++;
        cnt = t / 2;
        dir = (dir + 1) % 4;
    }
    cout << answer;
}