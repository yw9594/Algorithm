/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

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

	vector<int> answer(N + 1, 0);	  // �Ǽ� �Ϸ� �ð�
	vector<int> build_time(N + 1, 0); // �Ǽ� �ð�
	vector<int> in_edge(N + 1, 0);						// ���� ����
	vector<vector<int>> out_edge(N + 1, vector<int>());  // ���� ����

	// �Է�
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

	// ���� ����
	// ���� �Ǽ� �ð� = (���� �ǹ��� �ð�) + (�ڽ��� �Ǽ� �ð�)
	priority_queue<Pos, vector<Pos>, Pred> q; // ���� �ǹ� �ð����� �����Ѵ�.
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
			in_edge[e]--; // ���� ����
			if (in_edge[e] == 0) {
				q.push(Pos(e, answer[cur_building.first] + build_time[e]));
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << answer[i] << "\n";


	return 0;
}*/