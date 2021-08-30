#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[50001];
int depth[50001];
int parent[50001];

void dfs(int node) {
    for (int next : v[node]) {
        if (parent[next] != 0) 
            continue;
        depth[next] = depth[node] + 1;
        parent[next] = node;
        dfs(next);
    }
}

int lca(int a, int b) {
    while (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) {
            a = parent[a];
        } else {
            b = parent[b];
        }
    }

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    parent[1] = 1;
    depth[1] = 1;
    dfs(1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
