/* BOJ 11505
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long int init_tree(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		long long int left = init_tree(arr, tree, 2 * node, start, mid);		//left
		long long int right = init_tree(arr, tree, 2 * node + 1, mid + 1, end);   // right
		long long int center = 0LL;

		while (1) {

		}

		long long int max_area = left;
		max_area = max_area > right ? max_area : right;
		max_area = max_area > center ? max_area : center;

		return tree[node] = max_area;
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int N;
		cin >> N;

		if (N == 0) break;

		vector<long long int> arr(N + 1);
		int h = (int)ceil(log2(N)) + 1;
		int tree_size = (1 << h) - 1;

		vector<long long int> tree(tree_size + 1);

		for (int i = 1; i <= N; i++) cin >> arr[i];

		cout << init_tree(arr, tree, 1, 1, N) << "\n";

	}

	return 0;
}*/