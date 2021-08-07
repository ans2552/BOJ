#include <iostream>

using namespace std;

int parent[1000001];
int n, m;

int find(int i) {
    int pi = parent[i];
    if(i == pi)
        return i;
    return parent[i] = find(pi);
}

void Union(int a, int b){
    int pa = find(a);
    int pb = find(b);
    
    if(pa != pb) {
        parent[pa] = pb;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    
    for(int i = 0; i < m; i++){
        cin >> t >> a >> b;
        if(t == 0)
            Union(a, b);
        else {
            if(find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
