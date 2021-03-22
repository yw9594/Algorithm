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

int N, answer = 0;

struct Work {
	int id, time;
	Work(int id = -1, int time = -1) {
		this->id = id;
		this->time = time;
	}
};

struct Pred {
	bool operator()(Work& a, Work& b) {
		return a.time > b.time;
	}
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int> in_edge(N + 1, 0);
	vector<vector<int>> out_edge(N + 1, vector<int>());
	vector<int> work_time(N + 1, 0);

	for (int n = 1; n <= N; n++) {
		int t, m;
		cin >> t >> m;

		work_time[n] = t;
		while (m--) {
			int w;
			cin >> w;
			in_edge[n]++;
			out_edge[w].push_back(n);
		}

	}

	priority_queue<Work, vector<Work>, Pred> pq; // 우선 순위 큐

	// 선행 관계 없는 노드 삽입
	for (int i = 1; i <= N; i++) {
		if (in_edge[i] == 0) {
			pq.push(Work(i, work_time[i]));
		}
	}

	while (!pq.empty()) {
		Work cur_work = pq.top();
		pq.pop();

		answer = cur_work.time > answer ? cur_work.time : answer;


		for (auto& e : out_edge[cur_work.id]) {
			in_edge[e]--;
			if (in_edge[e] == 0) {
				pq.push(Work(e, cur_work.time + work_time[e]));
			}
		}

	}

	cout << answer << '\n';


	return 0;
}*/