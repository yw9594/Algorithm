/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int N, M;

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<int> in_edge(N + 1, 0);						 // 진입 간선의 개수 
	vector<vector<int>> out_edge(N + 1, vector<int>());  // 각 노드의 진출 간선의 대상 노드
	while (M--) { // 키가 큰 학생이 앞선다.
		int a, b;
		cin >> a >> b;
		in_edge[b]++;
		out_edge[a].push_back(b);
	}

	// 진입 간선이 0인 모든 학생 -> q
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in_edge[i] == 0) q.push(i);
	}

	// 위상정렬
	vector<int> answer;
	vector<int> checked(N + 1, 0);

	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		// 정답에 삽입
		answer.push_back(cur_node);
		checked[cur_node] = 1;

		// 현재 노드와 진입간선으로 연결된 모든 노드 연결 해제 후 queue에 삽입
		for (auto& e : out_edge[cur_node]) {
			in_edge[e]--; // 진입 간선 제거
			if (in_edge[e] == 0)
				q.push(e);
		}

		// 진출 간선 리스트 삭제
		out_edge[cur_node].clear();
	}

	// 정답 출력
	for (int i = 1; i <= N; i++) // 비교 대상에 포함되지 않은 학생의 경우
		if (checked[i] == 0)
			answer.push_back(i);


	for (auto& e : answer)
		cout << e << " ";
	cout << "\n";


	return 0;
}*/