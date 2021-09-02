#include <iostream>
#define MOD 1000000007
using namespace std;

int N, M, K;
long long seg[4000000];
int arr[1000001];

long long init_seg(int node, int start, int end) {
    if (start == end) return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = (init_seg(node * 2, start, mid) *
                        init_seg(node * 2 + 1, mid + 1, end)) %
                       MOD;
}

long long get_mul(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 1;
    }
    if (left <= start && end <= right) {
        return seg[node];
    }

    int mid = (start + end) / 2;
    return (get_mul(node * 2, start, mid, left, right) *
            get_mul(node * 2 + 1, mid + 1, end, left, right)) %
           MOD;
}

long long update_mul(int node, int start, int end, int idx, int value) {
    if (idx < start || end < idx) return seg[node];

    if (start == end) return seg[node] = value;

    int mid = (start + end) / 2;
    return seg[node] = (update_mul(node * 2, start, mid, idx, value) *
                        update_mul(node * 2 + 1, mid + 1, end, idx, value)) %
                       MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    init_seg(1, 1, N);

    int a, b, c;
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update_mul(1, 1, N, b, c);
            arr[b] = c;
        } else if (a == 2) {
            cout << get_mul(1, 1, N, b, c) << '\n';
        }
    }
}