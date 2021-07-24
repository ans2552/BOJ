#include <iostream>
#include <cstring>
using namespace std;

pair<int, int> info[9];

int check[10]; //아니면 0 맞으면 1
int answer;

int isPossible() {
    // 1이 1개 가능
    // 0이 8개 가능
    // 0이 1~7개면 1이 0개면 여러 경우가능 -1
    int candidate = 0;
    int possibleCnt = 0;
    int impossibleCnt = 0;
    int impossibleCandi = 0;
    for(int i= 1; i <= 9; i++){
        if(check[i] == 1) {
            possibleCnt++;
            candidate = i;
        }
        else if(check[i] == 0) {
            impossibleCnt++;
        }
        else
            impossibleCandi = i;
    }
    if(possibleCnt == 1)
        return candidate;
    
    if(impossibleCnt == 8)
        return impossibleCandi;
    else if(impossibleCnt < 8 && possibleCnt == 0)
        return -1;
    
    return 0;
}

int main() {
    for(int i = 0; i < 9; i++){
        cin >> info[i].second >> info[i].first;
    }
    
    for(int i = 0; i < 9; i++){
        memset(check, -1, sizeof(check));
        int isContinue = false;
        for(int j = 0; j < 9; j++){
            int now = check[info[j].first];
            if(i != j) {
                if(now != -1 && now != info[j].second){
                    isContinue = true;
                    break;
                }
                else
                    check[info[j].first] = info[j].second;
            }
            else {
                if(now != -1 && now != !info[j].second){
                    isContinue = true;
                    break;
                }
                else
                    check[info[j].first] = !info[j].second;
            }
        }
        if(isContinue)
            continue;
        int ret = isPossible();
        if(ret) {
            if (answer != 0)
                answer = -1;
            else
                answer = ret;
        }
    }
    
    if(answer == 0)
        cout << -1;
    else
        cout << answer;
}


