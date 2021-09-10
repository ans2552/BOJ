#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[15][15];
int cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int parent[8];

struct Road {
    int s;
    int e;
    int len;

    bool operator<(const Road& rhs) const { return len < rhs.len; }
};

int find(int x) {
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

bool Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa != pb) {
        parent[pa] = pb;
        return true;
    }
    return false;
}

bool isRange(int x, int y) { return x >= 0 && y >= 0 && x < N && y < M; }

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    arr[x][y] = cnt;

    while (!q.empty()) {
        int fx = q.front().first;
        int fy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = fx + dx[i];
            int ny = fy + dy[i];
            if (isRange(nx, ny) && arr[nx][ny] == 1) {
                q.push({nx, ny});
                arr[nx][ny] = cnt;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cnt = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    for (int i = 2; i < cnt; i++) {
        parent[i] = i;
    }

    vector<Road> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] != 0) {
                int start = arr[i][j];
                for (int k = 0; k < 4; k++) {
                    int nx = i;
                    int ny = j;
                    int end = 0;
                    int len = 0;
                    while (1) {
                        nx += dx[k];
                        ny += dy[k];
                        len++;
                        if (!isRange(nx, ny)) break;
                        if (arr[nx][ny] != 0) {
                            end = arr[nx][ny];
                            break;
                        }
                    }
                    if (end != 0 && start != end && len > 2) {
                        v.push_back({start, end, len - 1});
                    }
                }
            }
        }
    }

    sort(v.begin(), v.end());
    int answer = 0;
    int check = 0;
    for (auto vv : v) {
        if (Union(vv.s, vv.e)) {
            answer += vv.len;
            check++;
        }
        if (check == cnt - 3) break;
    }

    if (check == cnt - 3 && check != 0)
        cout << answer;
    else
        cout << -1;
}