#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

int primeCheck[MAX+1]; // 0이면 소수
int N;
vector<int> answer;

void func(int x){
    for(int i = 2; i < x-1; i++){
        if(primeCheck[i]==0 && primeCheck[x-i] == 0){
            answer.push_back(i);
            answer.push_back(x-i);
            return;
        }
    }
}

int main() {
    primeCheck[1] = 1;
    primeCheck[0] = 1;
    cin >> N;
    
    for(int i = 2; i * i <= N; i++){
        if(primeCheck[i] == 0){
            for(int j = i * i; j <= N; j += i){
                primeCheck[j] = 1;
            }
        }
    }
    if(N < 8){
        cout << -1;
    }
    else {
        if(N % 2 == 0){
            answer.push_back(2);
            answer.push_back(2);
            func(N-4);
        }
        else {
            answer.push_back(2);
            answer.push_back(3);
            func(N-5);
        }
        
        for(int ans: answer){
            cout << ans << ' ';
        }
    }
}
