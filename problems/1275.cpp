#include <iostream>

using namespace std;

int N, Q;
int arr[100001];
long long seg[400000];

long long init(int node, int start, int end) {
	if (start == end)
		return seg[node] = arr[end];

	int mid = (start + end) / 2;

	long long left = init(node * 2, start, mid);
	long long right = init(node * 2 +1, mid + 1, end);

	return seg[node] = left + right;
}

long long sum(int node, int start, int end, int left, int right) {
	if (left <= start && end <= right)
		return seg[node];
	
	if (end < left || right < start)
		return 0;
	
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || end < idx)
		return;

	seg[node] += diff;
	int mid = (start + end) / 2;
	if (start != end) {
		update(node * 2, start, mid, idx, diff);
		update(node * 2 + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	init(1, 1, N);
	int x, y, a;
	long long b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;

		if (x < y)
			cout << sum(1, 1, N, x, y) << '\n';
		else
			cout << sum(1, 1, N, y, x) << '\n';
		update(1, 1, N, a, b - arr[a]);
		arr[a] = b;
	}	
}