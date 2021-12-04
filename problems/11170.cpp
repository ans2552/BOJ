#include <iostream>
using namespace std;

int T,N,M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--){
        cin>>N>>M;
        int answer=0;
        for(int i=N;i<=M;i++){
            int num = i;
            if(num==0)
                answer++;
            
            while(num>0){
                if(num%10==0)
                    answer++;
                num/=10;
            }
        }
        cout << answer <<'\n';
    }
}