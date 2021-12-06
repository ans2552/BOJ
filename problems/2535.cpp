#include <iostream>
#include <algorithm>
using namespace std;

struct info {
	int country;
	int student;
	int score;
};
int countryCnt[101];
info arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i].country >> arr[i].student >> arr[i].score;
	}
		sort(arr, arr + N, [](info a, info b) {
		return a.score > b.score;
	});

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cnt == 3)
			break;
		if (countryCnt[arr[i].country] < 2) {
			countryCnt[arr[i].country]++;
			cout << arr[i].country << ' ' << arr[i].student << '\n';
			cnt++;
		}
	}
}