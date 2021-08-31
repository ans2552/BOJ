#include <iostream>
#include <vector>
#define MAX 100000000
using namespace std;

int N, M;
int A, B, C;
vector<pair<int, int>> v[501];
long long dist[501];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = MAX;
    }

    dist[1] = 0;
    bool isCycle = false;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[j] != MAX) {
                for (auto next : v[j]) {
                    if (dist[next.first] > dist[j] + next.second) {
                        dist[next.first] = dist[j] + next.second;
                        if (i == N) {
                            isCycle = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (isCycle) {
        cout << -1;
    } else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == MAX)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
}