#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dice[6];

// 동 남 서 북
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M, K;
int arr[20][20];
int visit[20][20];
int sameCnt[20][20];

void initDice() {
    dice[0] = 1;
    dice[1] = 5;
    dice[2] = 3;
    dice[3] = 6;
    dice[4] = 2;
    dice[5] = 4;
}

void roll(int dir) {
    int dice2[6];

    if (dir == 0) {
        dice2[0] = dice[5];
        dice2[1] = dice[1];
        dice2[2] = dice[0];
        dice2[3] = dice[2];
        dice2[4] = dice[4];
        dice2[5] = dice[3];
    } else if (dir == 1) {
        dice2[0] = dice[4];
        dice2[1] = dice[0];
        dice2[2] = dice[2];
        dice2[3] = dice[1];
        dice2[4] = dice[3];
        dice2[5] = dice[5];
    } else if (dir == 2) {
        dice2[0] = dice[2];
        dice2[1] = dice[1];
        dice2[2] = dice[3];
        dice2[3] = dice[5];
        dice2[4] = dice[4];
        dice2[5] = dice[0];
    } else if (dir == 3) {
        dice2[0] = dice[1];
        dice2[1] = dice[3];
        dice2[2] = dice[2];
        dice2[3] = dice[4];
        dice2[4] = dice[0];
        dice2[5] = dice[5];
    }

    dice[0] = dice2[0];
    dice[1] = dice2[1];
    dice[2] = dice2[2];
    dice[3] = dice2[3];
    dice[4] = dice2[4];
    dice[5] = dice2[5];
}

bool isRange(int x, int y) { return x >= 0 && y >= 0 && x < N && y < M; }

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;

    int now = arr[x][y];
    q.push({x, y});
    visit[x][y] = 1;
    int cnt = 0;

    while (!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        v.push_back(q.front());
        cnt++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if (isRange(nx, ny) && visit[nx][ny] == 0 && arr[nx][ny] == now) {
                q.push({nx, ny});
                visit[nx][ny] = 1;
            }
        }
    }
    for (pair<int, int> p : v) {
        sameCnt[p.first][p.second] = cnt;
    }
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    int dir = 0;
    int x = 0;
    int y = 0;
    int answer = 0;
    initDice();

    for (int i = 0; i < K; i++) {
        if (!isRange(x + dx[dir], y + dy[dir])) {
            dir = (dir + 2) % 4;
        }

        roll(dir);
        x += dx[dir];
        y += dy[dir];

        answer += sameCnt[x][y] * arr[x][y];
        if (dice[3] < arr[x][y]) {
            dir = (dir + 3) % 4;
        } else if (dice[3] > arr[x][y]) {
            dir = (dir + 1) % 4;
        }
    }
    cout << answer;
}