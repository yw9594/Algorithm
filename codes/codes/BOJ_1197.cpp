/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

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
	if (f_u_graph[node] == node) return node; // �θ� ��� �߰�
	else return f_u_graph[node] = find(f_u_graph[node]);
}


bool check_cycle(Edge& c_edge) {
	int a = c_edge.s, b = c_edge.e;

	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return true; // cycle �߻�
	else { // union
		f_u_graph[pb] = f_u_graph[pa];

		return false;
	}
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	cin >> V >> E;

	// ���� �Է�
	vector<Edge> edges;
	for (int i = 0; i < E; i++) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		edges.push_back({ n1, n2, w });
	}


	// ����ġ �� ���� 
	stable_sort(edges.begin(), edges.end());

	// find_union �ʱ�ȭ
	f_u_graph.resize(V + 1);
	for (int i = 0; i <= V; i++) f_u_graph[i] = i;


	//for (auto& e : edges)
	//	cout << e.s << " " << e.e << " " << e.w<<"\n";

	// ũ�罺Į ����
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