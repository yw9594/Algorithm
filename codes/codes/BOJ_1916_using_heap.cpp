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
#define INF 987654321

int N, M;
int start, dest;
vector<long long int> dist;
vector<vector<long long int>> weight;
vector<vector<int>> matrix;

struct Elem {
	int n;					// 노드 번호
	long long int w;		// 경로 가중치 합
	bool operator<(const Elem& arg) const {	// 경로에 포함되지 않은 노드 중 가장 경로합이 작은 노드
		return this->w > arg.w;
	}
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	dist = vector<long long int>(N + 1, INF);
	weight = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, INF));	// 가중치 배열 초기화
	matrix = vector<vector<int>>(N + 1, vector<int>()); // 인접 리스트 초기화

	// 입력 받기
	for (int i = 1; i <= M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		if (w < weight[s][e]) {
			weight[s][e] = w;		// 가중치 배열
			matrix[s].push_back(e); // 인접 리스트 
		}
	}
	cin >> start >> dest; // 출발지/목적지


	// 다익스트라 수행
	priority_queue<Elem> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		Elem cur_node = pq.top(); // 경로 집합에 포함되지 않은 노드 중, 가중합이 가장 작은 노드를 포함시킬 것이다.
		pq.pop();

		if (dist[cur_node.n] < cur_node.w) // 가고자하는 노드의 경로 가중합이 찾은 경로의 가중합보다 더 큰 경우, 연산을 수행하지 않는다. 
			continue;

		dist[cur_node.n] = cur_node.w; // 포함시킬 노드의 경로 합을 수정한다.				


		for (auto& e : matrix[cur_node.n]) {
			long long int new_dist = dist[cur_node.n] + weight[cur_node.n][e];// 현재 노드가 경로 집합에 포함됨에 따라 추가되는 갈 수 있는 노드들의 경로 합
			if (new_dist < dist[e]) { // 새로이 포함된 노드에서 다음 노드로 갈 경로 중 더 빠른 노드가 존재한다면 큐에 포함한다.
				pq.push({ e, new_dist });
			}
		}
	}
	//show_1d_array(dist);
	cout << dist[dest] << "\n";


	return 0;
}*/