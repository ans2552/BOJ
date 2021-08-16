#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100001];
int maxSeg[400000];
int minSeg[400000];

int init_max(int node, int start, int end) {
	if (start == end)
		return maxSeg[node] = arr[start];

	int mid = (start + end) / 2;
	 
	return maxSeg[node] = max(init_max(node * 2, start, mid), init_max(node * 2 + 1, mid + 1, end));
}

int init_min(int node, int start, int end) {
	if (start == end)
		return minSeg[node] = arr[start];

	int mid = (start + end) / 2;

	return minSeg[node] = min(init_min(node * 2, start, mid), init_min(node * 2 + 1, mid + 1, end));
}

int get_max(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
	}

	if (left <= start && end <= right) {
		return maxSeg[node];
	}

	int mid = (start + end) / 2;	
	return max(get_max(node * 2, start, mid, left, right), get_max(node * 2 + 1, mid + 1, end, left, right));
}

int get_min(int node, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 1000000001;
	}

	if (left <= start && end <= right) {
		return minSeg[node];
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

	init_max(1, 1, N);
	init_min(1, 1, N);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << get_min(1, 1, N, a, b) << ' ' << get_max(1, 1, N, a, b) << '\n';
	}
}