#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int indegree[100001];
int check[100001];
vector<int> v[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	int X, Y;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		indegree[Y]++;
		v[X].push_back(Y);
	}
	int answer = 0;
	for (int i = 0; i < K; i++) {
		cin >> X >> Y;
		if (X == 1) {
			if (indegree[Y] != 0) {
				answer = 1;
				break;
			}
			if (check[Y] == 0) {
				for (int node : v[Y]) {
					indegree[node]--;
				}
			}
			check[Y]++;
		}
		else if (X == 2) {
			if (check[Y] == 0) {
				answer = 1;
				break;
			}
			if (check[Y] == 1) {
				for (int node : v[Y]) {
					indegree[node]++;
				}
			}
			check[Y]--;
		}
	}

	if (answer)
		cout << "Lier!";
	else
		cout << "King-God-Emperor";
}