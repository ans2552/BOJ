#include <iostream>
using namespace std;

int N, M;
char arr[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visit[50][50];
int dp[50][50];

bool isRange(int x, int y) { return x >= 0 && y >= 0 && x < N && y < M; }

int dfs(int x, int y) {
    if (!isRange(x, y) || (arr[x][y] + '0' == 'H')) {
        return 0;
    }
    if (visit[x][y]) {
        return -1;
    }

    if (dp[x][y] != 0) return dp[x][y];

    visit[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] * arr[x][y];
        int ny = y + dy[i] * arr[x][y];
        int cnt = dfs(nx, ny);
        if (cnt == -1) {
            return -1;
        }
        dp[x][y] = max(dp[x][y], cnt + 1);
    }
    visit[x][y] = 0;
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            arr[i][j] -= '0';
        }
    }
    cout << dfs(0, 0);
}