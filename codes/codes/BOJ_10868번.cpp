/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int init_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end) {
	if (start == end) return tree[node] = arr[start]; // 단말 노드
	else {
		int mid = (start + end) / 2;
		int l_child = init_tree(arr, tree, 2 * node, start, mid);
		int r_child = init_tree(arr, tree, 2 * node + 1, mid+1, end);
		return tree[node] = l_child < r_child ? l_child : r_child;
	}
}

int partial_min(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 2100000000; // 구간합을 구할 수 없는 경우 : 최솟값이 없다.
	else if (left <= start && end <= right) return tree[node];
	else {
		int mid = (start + end) / 2;
		int l_val = partial_min(tree, 2 * node, start, mid, left, right);
		int r_val = partial_min(tree, 2 * node +1, mid+1, end, left, right);

		return l_val<r_val ? l_val : r_val;
	}
}

int main(void) {
	int N, M;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<int> arr(N+1);
	for (int i = 1; i <= N; i++) cin >> arr[i];

	int h = (int)ceil(log2(N))+1;
	int tree_size = (1 << h) - 1;

	vector<int> tree(tree_size); // segment tree

	init_tree(arr, tree, 1, 1, N);

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << partial_min(tree, 1, 1, N, a, b) << "\n";
	}
return 0;
}
*/