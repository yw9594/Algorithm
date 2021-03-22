/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////
#define INF 987654321
using Edge = pair<int, int>;

struct Elem {
	int n, w;
	bool operator<(const Elem& arg) const {
		return this->w > arg.w;
	}
};

int V, E, start;

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> V >> E >> start;
	vector<vector<Edge>> matrix(V + 1, vector<Edge>()); // 인접 리스트
	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		matrix[s].push_back({ e, w });
	}

	// 초기화
	vector<int> dist(V + 1);
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	// 다익스트라
	priority_queue<Elem> pq; // 경로 집합에 포함 가능한 노드들 집합
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Elem c_n = pq.top();
		pq.pop();

		if (dist[c_n.n] < c_n.w) continue; // 이미 더 작은 경로가 존재하는 경우 무시

		// 경로 집합에 포함될 노드 중, 더 작은 경로 가중치 합을 가진 친구들 pq에 삽입
		for (auto& e : matrix[c_n.n]) {
			int n_e = e.first,
				n_w = c_n.w + e.second; // 현재 경로 집합에 포함된 노드까지의 경로합과 아직 경로집합에 포함안된 노드간 간선 가중치 합
			if (n_w < dist[n_e]) {
				pq.push({ n_e, n_w });
				dist[n_e] = n_w;
			}
		}

	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}*/