#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
pair<int, int> lecture[100000];
priority_queue<int ,vector<int>, greater<int>> pq;
int answer;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t >> lecture[i].first >> lecture[i].second;
	}

	sort(lecture, lecture + N);
	
	for (int i = 0; i < N; i++) {
		answer++;		
		if (!pq.empty() && pq.top() <= lecture[i].first) {			
			answer--;
			pq.pop();	
		}
		pq.push(lecture[i].second);
	}
	cout << answer;
}