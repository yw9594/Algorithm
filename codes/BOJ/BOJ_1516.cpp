/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int N;

struct Pred {
	bool operator()(const Pos& a, const Pos& b) {
		return a.second > b.second;
	}
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> answer(N + 1, 0);	  // 건설 완료 시간
	vector<int> build_time(N + 1, 0); // 건설 시간
	vector<int> in_edge(N + 1, 0);						// 진입 간선
	vector<vector<int>> out_edge(N + 1, vector<int>());  // 진출 간선

	// 입력
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		build_time[i] = t;

		int e;
		while (1) {
			cin >> e;
			if (e == -1)break;
			in_edge[i]++;
			out_edge[e].push_back(i);
		}
	}

	// 위상 정렬
	// 최종 건설 시간 = (선행 건물의 시간) + (자신의 건설 시간)
	priority_queue<Pos, vector<Pos>, Pred> q; // 빠른 건물 시간부터 제거한다.
	for (int i = 1; i <= N; i++) {
		if (in_edge[i] == 0) {
			q.push(Pos(i, build_time[i]));
		}
	}

	while (!q.empty()) {
		Pos cur_building = q.top();
		q.pop();

		answer[cur_building.first] = cur_building.second;

		for (auto& e : out_edge[cur_building.first]) {
			in_edge[e]--; // 간선 제거
			if (in_edge[e] == 0) {
				q.push(Pos(e, answer[cur_building.first] + build_time[e]));
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << answer[i] << "\n";


	return 0;
}*/