#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000][10];
int visit[1000][10];
vector<int> answer;
bool isFind = false;

void dfs(int cnt, int before) {
	if (cnt == N) {
		isFind = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (arr[cnt][i] == 1 && i != before && visit[cnt][i] == 0) {
			visit[cnt][i] = 1;
			answer.push_back(i);
			dfs(cnt + 1, i);
			if (isFind)
				break;
			answer.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int m,type;
	for (int i = 0; i < N; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> type;
			arr[i][type] = 1;
		}
	}

	dfs(0, 0);

	if (isFind) {
		for (int ans : answer) {
			cout << ans << '\n';
		}
	}
	else
		cout << -1;
}
