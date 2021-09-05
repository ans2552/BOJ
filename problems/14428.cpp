#include <iostream>
#include <algorithm>
#define MAX 1000000001

using namespace std;

int N, M;
int arr[100001];
int seg[400000];

int init_seg(int node, int start, int end) {
	if (start == end)
		return seg[node] = start;

	int mid = (start + end) / 2;
	int a = init_seg(node * 2, start, mid);
	int b = init_seg(node * 2 + 1, mid + 1, end);

	if (arr[a] < arr[b])
		return seg[node] = a;
	else if (arr[a] == arr[b])
		return seg[node] = min(a, b);
	else
		return seg[node] = b;
}

int get_min(int node, int start, int end, int left, int right) {
	if (end < left || right < start)
		return 0;

	if (left <= start && end <= right)
		return seg[node];

	int mid = (start + end) / 2;
	int a = get_min(node * 2, start, mid, left, right);
	int b = get_min(node * 2 + 1, mid + 1, end, left, right);
	if (arr[a] < arr[b])
		return a;
	else if (arr[a] == arr[b])
		return min(a, b);
	else
		return b;
}

int update(int node, int start, int end, int idx, int v) {
	if (end < idx || idx < start)
		return seg[node];

	if (start == end)
		return idx;

	int mid = (start + end) / 2;
	int a = update(node * 2, start, mid, idx, v);
	int b = update(node * 2 + 1, mid + 1, end, idx, v);

	if (arr[a] < arr[b])
		return seg[node] = a;
	else if (arr[a] == arr[b])
		return seg[node] = min(a, b);
	else
		return seg[node] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	arr[0] = MAX;
	init_seg(1, 1, N);

	cin >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			update(1, 1, N, b, c);
		}
		else if (a == 2)
			cout << get_min(1, 1, N, b, c) << '\n';
	}
}