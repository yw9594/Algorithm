/* 세그먼트 트리 정리
BOJ 114411번 합 구하기
 https://www.acmicpc.net/problem/11441

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// arr : 입력 배열
// tree : 세그먼트 트리 배열
// node : 현재 저장할 노드 번호. 부모 노드의 경우 구간 합을 의미한다.
// start~end : 노드의 관리 범위 
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

// tree : 세그먼트 트리 
// left/right : 구간 합의 범위
// start/end : node의 관리 범위 
int partialSum(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) { // 구간합의 범위가 노드의 범위를 벗어나는 경우
		return 0; // 해당 서브 트리에서 구간합을 절대 구할 수 없다. 
				  // 반대쪽 서브 트리에서 구간합이 구해질 것이다.
	}	
	else if (left<=start && end<=right) { // 구간 합의 일부를 나타내는 세그먼트를 마주쳤을 경우
		return tree[node];	// 해당 구간합을 가져온다.
							// 해당 노드 밑의 노드들까지 내려갈 필요가 없다.
	}
	return // 구간합의 구간과 노드의 범위가 겹쳐있는 경우, 반으로 쪼개 탐색한다. 
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

	// 배열 입력
	cin >> N;
	arr.resize(N+1);
	for (int i = 1; i <= N; i++) cin >> arr[i];

	// 트리 생성
	// 리프노드 포함 필요 노드 개수 : 2^(H+1)-1, 
	// 리프노드 제외한 높이 : H = ceil(log(N)),   
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h+1)) - 1;
	tree.resize(tree_size);    

	// segment tree 생성
	init_tree(arr, tree, 1, 1, N);

	// 구간합 계산
	cin >> M;
	while (M--) {
		int answer;
		int left, right;
		cin >> left >> right;
		answer = partialSum(tree, 1, 1, N, left, right);
		cout << answer << "\n";
	}

	return 0;
}*/