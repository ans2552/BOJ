#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int arr[3][3];
pair<int, int> pos;
unordered_map<string, int> visit;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

string arrToString() {
    string ret = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret.push_back(arr[i][j] + '0');
        }
    }
    return ret;
}

void setArr(string s) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = s[3 * i + j] - '0';
            if (arr[i][j] == 0) 
                pos = {i, j};
        }
    }
}
bool isRange(int x, int y) { 
    return x >= 0 && y >= 0 && x < 3 && y < 3; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) 
                pos = {i, j};
        }
    }
    string s = arrToString();
    queue<string> q;
    q.push(s);
    visit[s] = 1;
    int answer = 0;
    while (!q.empty()) {
        string f = q.front();
        if (f == "123456780") {
            answer = visit[f];
            break;
        }
        q.pop();
        setArr(f);
        int cnt = visit[f];
        for (int i = 0; i < 4; i++) {
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];

            if (isRange(nx, ny)) {
                swap(arr[nx][ny], arr[pos.first][pos.second]);
                string now = arrToString();
                if (visit.find(now) == visit.end()) {
                    visit[now] = cnt + 1;
                    q.push(now);
                }
                swap(arr[nx][ny], arr[pos.first][pos.second]);
            }
        }
    }
    cout << answer - 1;
}
