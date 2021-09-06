#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

char arr[12][6];
int visit[12][6];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int check = 0;

bool isRange(int x, int y) { 
    return x >= 0 && y >= 0 && x < 12 && y < 6; 
}

void bfs(int i, int j) {
    memset(visit, 0, sizeof(visit));
    char now = arr[i][j];
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = 1;
    int cnt = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (isRange(nx, ny) && arr[nx][ny] == now && visit[nx][ny] == 0) {
                q.push({nx, ny});
                visit[nx][ny] = 1;
            }
        }
    }

    if (cnt >= 4) {
        check = 1;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (visit[i][j] == 1) arr[i][j] = '.';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    while (1) {
        check = 0;
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (arr[i][j] != '.') {
                    bfs(i, j);
                }
            }
        }

        if (check == 0) 
            break;

        //당기기
        answer++;
        for (int j = 0; j < 6; j++) {
            for (int i = 11; i >= 0; i--) {
                if (arr[i][j] == '.') {
                    for (int k = i - 1; k >= 0; k--) {
                        if (arr[k][j] != '.') {
                            arr[i][j] = arr[k][j];
                            arr[k][j] = '.';
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << answer;
}