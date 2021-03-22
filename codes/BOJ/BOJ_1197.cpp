/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int V, E;
vector<int> f_u_graph; // find_union graph

struct Edge {
	int s, e;
	long long int w;
	bool operator<(const Edge& arg) const {
		return this->w < arg.w;
	}
};


int find(int node) {
	if (f_u_graph[node] == node) return node; // 부모 노드 발견
	else return f_u_graph[node] = find(f_u_graph[node]);
}


bool check_cycle(Edge& c_edge) {
	int a = c_edge.s, b = c_edge.e;

	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return true; // cycle 발생
	else { // union
		f_u_graph[pb] = f_u_graph[pa];

		return false;
	}
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> V >> E;

	// 간선 입력
	vector<Edge> edges;
	for (int i = 0; i < E; i++) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		edges.push_back({ n1, n2, w });
	}


	// 가중치 별 정렬 
	stable_sort(edges.begin(), edges.end());

	// find_union 초기화
	f_u_graph.resize(V + 1);
	for (int i = 0; i <= V; i++) f_u_graph[i] = i;


	//for (auto& e : edges)
	//	cout << e.s << " " << e.e << " " << e.w<<"\n";

	// 크루스칼 적용
	long long int answer = 0;
	int cnt = 0;
	for (auto& e : edges) {
		Edge& c_edge = e;

		if (!check_cycle(e)) {
			cnt++;
			answer += c_edge.w;


			if (cnt == V - 1)
				break;
		}
	}
	cout << answer << "\n";

	return 0;
}*/