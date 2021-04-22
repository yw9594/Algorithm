/* ���׸�Ʈ Ʈ�� ����
BOJ 114411�� �� ���ϱ�
 https://www.acmicpc.net/problem/11441
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// arr : �Է� �迭
// tree : ���׸�Ʈ Ʈ�� �迭
// node : ���� ������ ��� ��ȣ. �θ� ����� ��� ���� ���� �ǹ��Ѵ�.
// start~end : ����� ���� ���� 
int init_tree(vector<int> & arr, vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	else {
		int left_node = 2 * node;
		int right_node = 2 * node + 1;

		return tree[node] =
			init_tree(arr, tree, left_node, start, (start + end) / 2) +
			init_tree(arr, tree, right_node, 1 + ((start + end) / 2), end);
	}
}

// tree : ���׸�Ʈ Ʈ�� 
// left/right : ���� ���� ����
// start/end : node�� ���� ���� 
int partialSum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) { // �������� ������ ����� ������ ����� ���
		return 0; // �ش� ���� Ʈ������ �������� ���� ���� �� ����. 
				  // �ݴ��� ���� Ʈ������ �������� ������ ���̴�.
	}	
	else if (left<=start && end<=right) { // ���� ���� �Ϻθ� ��Ÿ���� ���׸�Ʈ�� �������� ���
		return tree[node];	// �ش� �������� �����´�.
							// �ش� ��� ���� ������� ������ �ʿ䰡 ����.
	}
	return // �������� ������ ����� ������ �����ִ� ���, ������ �ɰ� Ž���Ѵ�. 
		partialSum(tree, 2*node, start, (start+end)/2, left, right) + 
		partialSum(tree, 2*node + 1, 1+((start + end)/2), end, left, right);
}


int main(void) {
	int N, M;
	vector<int> arr;
	vector<int> tree;	// segment tree

	freopen("input.txt", "r", stdin);
	std::iostream::sync_with_stdio(false);
	cin.tie(NULL);

	// �迭 �Է�
	cin >> N;
	arr.resize(N+1);
	for (int i = 1; i <= N; i++) cin >> arr[i];

	// Ʈ�� ����
	// ������� ���� �ʿ� ��� ���� : 2^(H+1)-1, 
	// ������� ������ ���� : H = ceil(log(N)),   
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h+1)) - 1;
	tree.resize(tree_size);    

	// segment tree ����
	init_tree(arr, tree, 1, 1, N);

	// ������ ���
	cin >> M;
	while (M--) {
		int answer;
		int left, right;
		cin >> left >> right;
		answer = partialSum(tree, 1, 1, N, left, right);
		cout << answer << "\n";
	}

	return 0;
}