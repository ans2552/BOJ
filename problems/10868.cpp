#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int N, M;
int seg[400000];

int init(int node, int start, int end) {
	if (start == end)
		return seg[node] = arr[start];

	int mid = (start + end) / 2;
	return seg[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int get_min(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 1000000001;

	if (left <= start && end <= right) {
		return seg[node];
	}

	int mid = (start + end) / 2;	
	return min(get_min(node * 2, start, mid, left, right), get_min(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init(1, 1, N);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << get_min(1, 1, N, a, b) << '\n';
	}
}