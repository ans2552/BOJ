#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

int N, Q;
int arr[64][64];
int L;
int arrSize;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int visit[64][64];
int land;
int ice;

bool isRange(int x, int y) {
    return x >= 0 && y >= 0 && x < arrSize && y < arrSize;
}

void rotate(int l) {
    int tmp[64][64];
    l = pow(2, l);
    for (int i = 0; i < arrSize; i += l) {
        for (int j = 0; j < arrSize; j += l) {
            for (int di = 0; di < l; di++) {
                for (int dj = 0; dj < l; dj++) {
                    tmp[i + dj][j + l - 1 - di] = arr[i + di][j + dj];
                }
            }
        }
    }

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visit[x][y] = 1;
    q.push({x, y});
    int cnt = 0;
    while (!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        ice += arr[fx][fy];

        cnt++;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if (isRange(nx, ny) && visit[nx][ny] == 0 && arr[nx][ny] > 0) {
                visit[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    land = max(land, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    arrSize = pow(2, N);

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int>> q;
    while (Q--) {
        cin >> L;
        rotate(L);
        for (int i = 0; i < arrSize; i++) {
            for (int j = 0; j < arrSize; j++) {
                int cnt = 0;
                if (arr[i][j] <= 0) continue;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (isRange(nx, ny) && arr[nx][ny] > 0) cnt++;
                }

                if (cnt < 3) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            arr[x][y]--;
        }
    }

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (arr[i][j] > 0 && visit[i][j] == 0) bfs(i, j);
        }
    }
    cout << ice << '\n' << land;
}