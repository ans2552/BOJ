#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> minusLoc;
vector<int> plusLoc;
int answer;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int location;
    for(int i = 0; i < N; i++){
        cin >> location;
        if(location > 0)
            plusLoc.push_back(location);
        else
            minusLoc.push_back(location * -1);
    }
    
    sort(plusLoc.begin(), plusLoc.end(), greater<int>());
    sort(minusLoc.begin(), minusLoc.end(), greater<int>());
    
    for(int i = 0; i < plusLoc.size(); i += M){
        answer += plusLoc[i];
    }
    for(int i = 0; i < minusLoc.size(); i += M){
        answer += minusLoc[i];
    }
    
    answer *= 2;
    if(plusLoc.size() == 0)
        answer -= minusLoc[0];
    else if (minusLoc.size() == 0)
        answer -= plusLoc[0];
    else {
        if(plusLoc[0] < minusLoc[0])
            answer -= minusLoc[0];
        else
            answer -= plusLoc[0];
    }
    
    cout << answer;
}
