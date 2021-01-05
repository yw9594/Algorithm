/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int N, M;

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<int> in_edge(N + 1, 0);						 // ���� ������ ���� 
	vector<vector<int>> out_edge(N + 1, vector<int>());  // �� ����� ���� ������ ��� ���
	while (M--) { // Ű�� ū �л��� �ռ���.
		int a, b;
		cin >> a >> b;
		in_edge[b]++;
		out_edge[a].push_back(b);
	}

	// ���� ������ 0�� ��� �л� -> q
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in_edge[i] == 0) q.push(i);
	}

	// ��������
	vector<int> answer;
	vector<int> checked(N + 1, 0);

	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		// ���信 ����
		answer.push_back(cur_node);
		checked[cur_node] = 1;

		// ���� ���� ���԰������� ����� ��� ��� ���� ���� �� queue�� ����
		for (auto& e : out_edge[cur_node]) {
			in_edge[e]--; // ���� ���� ����
			if (in_edge[e] == 0)
				q.push(e);
		}

		// ���� ���� ����Ʈ ����
		out_edge[cur_node].clear();
	}

	// ���� ���
	for (int i = 1; i <= N; i++) // �� ��� ���Ե��� ���� �л��� ���
		if (checked[i] == 0)
			answer.push_back(i);


	for (auto& e : answer)
		cout << e << " ";
	cout << "\n";


	return 0;
}*/