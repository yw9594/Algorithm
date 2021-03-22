/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////
struct Edge {
	int a, b, w;
	bool operator<(const Edge& arg) const {
		return this->w < arg.w;
	}
};

int N, M, answer = 0;
vector<Edge> edges;
vector<int> tree;

int find_root(int node) {
	if (tree[node] == node) return node;
	else return tree[node] = find_root(tree[node]);
}

bool find_union(Edge& edge) {
	int a = edge.a, b = edge.b;

	int pa = find_root(a), pb = find_root(b);

	if (pa != pb) {
		tree[pb] = pa;
		return true;
	}
	else return false;

}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> N >> M;

	edges = vector<Edge>(M, { 0,0,0 });
	tree = vector<int>(N + 1, 0);

	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[m] = { a,b,c };
	}

	// 크루스칼 알고리즘
	stable_sort(edges.begin(), edges.end());

	for (int i = 0; i <= N; i++) tree[i] = i;

	int cnt = 0; // 추가된 간선 개수
	for (int i = 0; i < M; i++) {
		Edge c_e = edges[i];

		if (find_union(c_e)) {
			answer += c_e.w;
			cnt++;
		}
		if (cnt == N - 1) break;
	}

	cout << answer << "\n";

	return 0;
}*/