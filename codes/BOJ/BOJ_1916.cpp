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
#define INF 92233720368

int N, M;
int start, dest;
long long int dist[1001];
vector<int> pushed;
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

	weight = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, INF));	// 가중치 배열 초기화
	matrix = vector<vector<int>>(N + 1, vector<int>()); // 인접 리스트 초기화


	// 입력 받기
	for (int i = 1; i <= M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		weight[s][e] = w;		// 가중치 배열
		matrix[s].push_back(e); // 인접 리스트 
	}
	cin >> start >> dest; // 출발지/목적지




	// 다익스트라 수행
	fill(dist, dist + 1001, INF);
	dist[start] = 0;
	pushed = vector<int>(N + 1, 0); // 경로 집합에 포함되는지 여부 체크

	vector<int> path_set;
	int cur_node = start;
	pushed[cur_node] = 1;


	while (path_set.size() != N) {
		// 현재 노드, 경로 집합 삽입 
		path_set.push_back(cur_node);


		// 경로 집합에서 갈 수 있는 노드, 경로 갱신
		for (auto& e : matrix[cur_node]) {
			dist[e] = (dist[e] <= weight[cur_node][e] + dist[cur_node]) ? dist[e] : weight[cur_node][e] + dist[cur_node];
		}


		// 현재 경로 집합에서 경로 집합에 포함되지 않은 노드 중, 가장 경로 가중치 합이 작은 노드 선택
		cur_node = 0; // 최솟값을 찾기 위한 더미 데이터 
		for (int i = 1; i <= N; i++) {
			if (!pushed[i] && dist[i] < dist[cur_node]) {
				cur_node = i;
			}
		}
		pushed[cur_node] = 1;


		for (int i = 1; i <= N; i++)
			cout << dist[i] << " ";
		cout << "\n";

	}

	cout << dist[dest] << "\n";

	return 0;
}*/