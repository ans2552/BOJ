#include <iostream>
#include <string>
using namespace std;

int N, M;
int arr[50][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	string dna;
	for (int i = 0; i < N; i++) {
		cin >> dna;
		for (int j = 0; j < dna.length(); j++) {
			if (dna[j] == 'A') {
				arr[j][0]++;
			}
			else if (dna[j] == 'C') {
				arr[j][1]++;
			}
			else if (dna[j] == 'G') {
				arr[j][2]++;
			}
			else if (dna[j] == 'T') {
				arr[j][3]++;
			}
		}
	}

	int result = 0;
	string answer = "";
	for (int i = 0; i < M; i++) {
		int idx = 0, cnt = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] > cnt) {
				idx = j;
				cnt = arr[i][j];
			}
		}

		result += (N - cnt);
		if (idx == 0) {
			answer += 'A';
		}
		else if (idx == 1) {
			answer += 'C';
		}
		else if (idx == 2) {
			answer += 'G';
		}
		else if (idx == 3) {
			answer += 'T';
		}
	}

	cout << answer << "\n" << result;
}