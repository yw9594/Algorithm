/*#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long int init_tree(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end) {
	if (start == end) return 0LL; // �迭 ���� 1���� �̹� ���ĵǾ� �ִ� �����̴�.
	else { // �κ� �������� swap�� �߻��ϴ� Ƚ�� 
		int mid = (start + end) / 2;
		long long int l_val = init_tree(arr, tree, 2 * node, start, mid);		// ���� ������ swap ����
		long long int r_val = init_tree(arr, tree, 2 * node + 1, mid + 1, end);   // ������ ������ swap ����
		long long int cnt = 0, k = 0;												// ���� ��忡���� swap ����
		int i = start, j = mid + 1;		// 2 index ����
		;
		// swap ���� ���ϱ�
		while (i <= mid && j <= end) {
			if (arr[i] > arr[j]) {
				cnt += (j - i - k); // j��° ���Ұ� i ��ġ���� swap�õ�. �� �� �̹� ���ĵ� ���Ҹ�ŭ ���ش�.
				k++, j++;
			}
			else i++; // ���ų�, ������ �迭�� ���Ұ� �� ū ���, swap�ؼ� �ȵȴ�.
		}
		sort(arr.begin() + start, arr.begin() + 1 + end); // <- double index���� ���� ����(O(NlogN)->O(N))

		return cnt + l_val + r_val;
	}
}

int main(void) {
	int N, M;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<long long int> arr(N + 1);
	for (int i = 1; i <= N; i++) cin >> arr[i];

	int h = (int)ceil(log2(N)) + 1;
	int tree_size = (1 << h) - 1;
	vector<long long int> tree(tree_size);

	cout << init_tree(arr, tree, 1, 1, N);


	return 0;
}*/