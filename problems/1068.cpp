#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> child[50];
int del;
int answer;

void dfs(int x) {
    if (child[x].size() == 0 || (child[x].size() == 1 && child[x][0] == del)) {
        answer++;
        return;
    }

    for (int c : child[x]) {
        if (c == del)
            continue;
        dfs(c);
    }
}

int main() {
    cin >> N;
    int p;
    int root = 0;
    for (int i = 0; i < N; i++) {
        cin >> p;
        if (p == -1)
            root = i;
        else
            child[p].push_back(i);
    }
    cin >> del;
    if (del != root)
        dfs(root);
    cout << answer;
}
