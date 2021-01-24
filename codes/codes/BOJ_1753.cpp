/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////
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

	// �Է�
	cin >> V >> E >> start;
	vector<vector<Edge>> matrix(V + 1, vector<Edge>()); // ���� ����Ʈ
	for (int i = 0; i < E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		matrix[s].push_back({ e, w });
	}

	// �ʱ�ȭ
	vector<int> dist(V + 1);
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	// ���ͽ�Ʈ��
	priority_queue<Elem> pq; // ��� ���տ� ���� ������ ���� ����
	pq.push({ start, 0 });
	dist[start] = 0;

	while (!pq.empty()) {
		Elem c_n = pq.top();
		pq.pop();

		if (dist[c_n.n] < c_n.w) continue; // �̹� �� ���� ��ΰ� �����ϴ� ��� ����

		// ��� ���տ� ���Ե� ��� ��, �� ���� ��� ����ġ ���� ���� ģ���� pq�� ����
		for (auto& e : matrix[c_n.n]) {
			int n_e = e.first,
				n_w = c_n.w + e.second; // ���� ��� ���տ� ���Ե� �������� ����հ� ���� ������տ� ���Ծȵ� ��尣 ���� ����ġ ��
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