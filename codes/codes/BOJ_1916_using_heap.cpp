/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;


/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////
#define INF 9876543210

using LL = long long int;
typedef pair<int, LL> Pos;

struct Elem {
	int n;
	LL w; // 노드 번호, 경로 합
	bool operator<(const Elem& arg) const {
		return this->w > arg.w;
	}
};

int N, M;
int start, dest;
vector<LL> dist;
vector<vector<Pos>> matrix;

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	dist = vector<LL>(N + 1, INF); // 가중치를 포함하는 인접리스트 
	matrix = vector<vector<Pos>>(N + 1, vector<Pos>()); // 가중치를 포함하는 인접리스트 

	// 입력
	while (M--) {
		int s, e, w;
		cin >> s >> e >> w;
		matrix[s].push_back({ e, w });
	}
	cin >> start >> dest;


	// 다익스트라
	priority_queue<Elem> pq;
	pq.push({ start, 0 }); // 시작노드는 경로집합에 포함한다.
	dist[start] = 0;

	while (!pq.empty()) {
		Elem cur_node = pq.top();
		pq.pop();

		// 현재 노드보다 이미 찾은 경로합이 더 작은 경우 현재 경로는 무시한다. 
		if (dist[cur_node.n] < cur_node.w)
			continue;

		// 경로집합에 포함되지 않은 원소들 중에서 가중합이 더 작아지는 노드들을 골라 넣는다.
		for (auto& e : matrix[cur_node.n]) {
			LL new_weight = dist[cur_node.n] + e.second; // 현재 노드를 거쳐 노드 e로 가는 경로 가중 합
			if (new_weight < dist[e.first]) {
				pq.push({ e.first, new_weight });
				dist[e.first] = new_weight;
			}
		}

	}


	cout << dist[dest] << "\n";

	return 0;
}*/