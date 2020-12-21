/*#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long int init_tree(vector<long long int>& arr, vector<long long int>& tree, int node, int start, int end) {
	if (start == end) return 0LL; // 배열 원소 1개는 이미 정렬되어 있는 상태이다.
	else { // 부분 구간에서 swap이 발생하는 횟수 
		int mid = (start + end) / 2;
		long long int l_val = init_tree(arr, tree, 2 * node, start, mid);		// 왼쪽 범위의 swap 개수
		long long int r_val = init_tree(arr, tree, 2 * node + 1, mid + 1, end);   // 오른쪽 범위의 swap 개수
		long long int cnt = 0, k = 0;												// 현재 노드에서의 swap 개수
		int i = start, j = mid + 1;		// 2 index 정렬
		;
		// swap 개수 구하기
		while (i <= mid && j <= end) {
			if (arr[i] > arr[j]) {
				cnt += (j - i - k); // j번째 원소가 i 위치까지 swap시도. 이 때 이미 정렬된 원소만큼 빼준다.
				k++, j++;
			}
			else i++; // 같거나, 오른쪽 배열의 원소가 더 큰 경우, swap해선 안된다.
		}
		sort(arr.begin() + start, arr.begin() + 1 + end); // <- double index으로 개선 가능(O(NlogN)->O(N))

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