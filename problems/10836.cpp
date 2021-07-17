#include <iostream>
using namespace std;

int M,N;
int arr[1400];
int ans[700][700];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;
    int a,b,c;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        arr[a]++;
        arr[a+b]++;
    }
    
    ans[M-1][0] += arr[0]+1;
    for(int i=1; i < M*2 -1; i++){
        arr[i] += arr[i-1];
        if(i<M)
            ans[M-1-i][0] += arr[i] + 1;
        else
            ans[0][i-M+1] += arr[i] + 1;
    }
    
    for(int i=0; i<M; i++){
        cout << ans[i][0] <<' ';
        for(int j=1; j<M; j++){
            cout << ans[0][j] <<' ';
        }
        cout <<'\n';
    }
}
