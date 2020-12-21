/*#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int init_tree(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start]; // ���� ���� �κ��� : �迭 ���� ��ü
	}
	else {
		int mid = (start + end) / 2;

		return tree[node] =
			init_tree(arr, tree, 2 * node, start, mid) +
			init_tree(arr, tree, 2 * node + 1, mid + 1, end);
	}
}

long long int partial_sum(vector<long long int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	else if (left <= start && end <= right) return tree[node]; // �Ǽ�!
	else {
		return
			partial_sum(tree, 2 * node, start, (start + end) / 2, left, right) +
			partial_sum(tree, 2 * node + 1, 1 + (start + end) / 2, end, left, right);
	}
}

void update(vector<long long int>& tree, int node, int start, int end, int index, long long int diff) {
	if (index < start || index > end) { // �ε����� ���Ե��� �ʴ� ��� �Ѿ��
		return;
	}

	tree[node] += diff; // ����� ���� ���� �ε����� ���ԵǴ� ��� ���̸�ŭ ����

	if (start != end) {
		int mid = (start + end) / 2;
		update(tree, 2 * node, start, mid, index, diff);
		update(tree, 2 * node + 1, mid + 1, end, index, diff);
	}
}

int main(void) {
	int N, M, K;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	int h = (int)ceil(log2(N)) + 1;
	int tree_size = (1 << h) - 1;
	vector<long long int> arr(N + 1);
	vector<long long int> tree(tree_size + 1); // ���׸�Ʈ Ʈ�� // �Ǽ�!!
	for (int i = 1; i <= N; i++) cin >> arr[i];

	init_tree(arr, tree, 1, 1, N); // ���׸�Ʈ Ʈ�� ����

	for (int t = 0; t < M + K; t++) {
		long long int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(tree, 1, 1, N, b, c - arr[b]);
			arr[b] = c;
		}
		else { // a==2
			cout << partial_sum(tree, 1, 1, N, b, c) << "\n";
		}
	}
	return 0;
}*/