/*#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

long long int init_tree(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];
	else {
		int mid = (start + end) / 2;
		return tree[node] =
			((init_tree(arr, tree, 2 * node, start, mid) % MOD) *
			(init_tree(arr, tree, 2 * node + 1, mid + 1, end) % MOD)) % MOD;
	}
}

long long int partialMul(vector<long long int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1LL; // 해당 구간에 곱 없음
	else if (left <= start && end <= right) return tree[node]; // 트리값 반환
	else {
		int mid = (start + end) / 2;
		return
			((partialMul(tree, 2 * node, start, mid, left, right) % MOD) *
			(partialMul(tree, 2 * node + 1, mid + 1, end, left, right) % MOD)) % MOD;
	}
}

long long int update(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end, int index, long long int val) {
	if (start == end) return arr[index] = tree[node] = val;
	else {
		int mid = (start + end) / 2;
		if (start <= index && index <= mid) {
			long long int l_child = update(arr, tree, 2 * node, start, mid, index, val);
			long long int r_child = tree[2 * node + 1];
			return tree[node] = (l_child * r_child) % MOD;
		}
		else {
			long long int l_child = tree[2 * node];
			long long int r_child = update(arr, tree, 2 * node + 1, mid + 1, end, index, val);
			return tree[node] = (l_child * r_child) % MOD;
		}
	}
}
int main(void) {
	int N, M, K;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	vector<long long int> arr(N + 1);
	int h = (int)ceil(log2(N)) + 1;
	int tree_size = (1 << h) - 1;
	vector<long long int> tree(tree_size);

	for (int i = 1; i <= N; i++) cin >> arr[i];

	init_tree(arr, tree, 1, 1, N);


	for (int i = 0; i < M + K; i++) {
		long long int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) { // update
			update(arr, tree, 1, 1, N, b, c);
		}
		else { // partialMul
			cout << partialMul(tree, 1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}*/