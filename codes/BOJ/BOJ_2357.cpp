/*#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int init_tree(vector<int>& arr, vector<int>& tree, int node, int start, int end, bool is_max) {
	if (start == end) {

		return tree[node] = arr[start];
	}
	else {

		int mid = (start + end) / 2;

		int left = init_tree(arr, tree, 2 * node, start, mid, is_max);
		int right = init_tree(arr, tree, 2 * node + 1, mid + 1, end, is_max);

		if (is_max) return tree[node] = left > right ? left : right; // 최댓값 세그먼트 트리
		else return tree[node] = left < right ? left : right; // 최솟값 세그먼트 트리
	}
}

int partial_val(vector<int>& tree, int node, int start, int end, int left, int right, bool is_max) {

	if (left > end || right < start) return is_max ? 0 : 2100000000; // 범위를 벗어난 경우 
	else if (left <= start && end <= right) return tree[node];
	else {
		int mid = (start + end) / 2;

		int l_child = partial_val(tree, 2 * node, start, mid, left, right, is_max);
		int r_child = partial_val(tree, 2 * node + 1, mid + 1, end, left, right, is_max); // 실수

		if (is_max) return l_child > r_child ? l_child : r_child;
		else return l_child < r_child ? l_child : r_child;
	}

}

int main(void) {
	int N, M;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<int> arr(N + 1);
	int h = (int)ceil(log2(N)) + 1;
	int tree_size = (1 << h) - 1;

	vector<int> tree_max(tree_size); // segment tree
	vector<int> tree_min(tree_size); // segment tree
	for (int i = 1; i <= N; i++) cin >> arr[i];

	init_tree(arr, tree_min, 1, 1, N, false);	// 구간 최솟값
	init_tree(arr, tree_max, 1, 1, N, true);	// 구간 최댓값 


	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << partial_val(tree_min, 1, 1, N, a, b, false) << " ";
		cout << partial_val(tree_max, 1, 1, N, a, b, true) << "\n";
	}


	return 0;
}*/