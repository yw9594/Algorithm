/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////
#define INF 987654321

int N, M;
int start, dest;
vector<long long int> dist;
vector<vector<long long int>> weight;
vector<vector<int>> matrix;

struct Elem {
	int n;					// ��� ��ȣ
	long long int w;		// ��� ����ġ ��
	bool operator<(const Elem& arg) const {	// ��ο� ���Ե��� ���� ��� �� ���� ������� ���� ���
		return this->w > arg.w;
	}
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	dist = vector<long long int>(N + 1, INF);
	weight = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, INF));	// ����ġ �迭 �ʱ�ȭ
	matrix = vector<vector<int>>(N + 1, vector<int>()); // ���� ����Ʈ �ʱ�ȭ

	// �Է� �ޱ�
	for (int i = 1; i <= M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		if (w < weight[s][e]) {
			weight[s][e] = w;		// ����ġ �迭
			matrix[s].push_back(e); // ���� ����Ʈ 
		}
	}
	cin >> start >> dest; // �����/������


	// ���ͽ�Ʈ�� ����
	priority_queue<Elem> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		Elem cur_node = pq.top(); // ��� ���տ� ���Ե��� ���� ��� ��, �������� ���� ���� ��带 ���Խ�ų ���̴�.
		pq.pop();

		if (dist[cur_node.n] < cur_node.w) // �������ϴ� ����� ��� �������� ã�� ����� �����պ��� �� ū ���, ������ �������� �ʴ´�. 
			continue;

		dist[cur_node.n] = cur_node.w; // ���Խ�ų ����� ��� ���� �����Ѵ�.				


		for (auto& e : matrix[cur_node.n]) {
			long long int new_dist = dist[cur_node.n] + weight[cur_node.n][e];// ���� ��尡 ��� ���տ� ���Եʿ� ���� �߰��Ǵ� �� �� �ִ� ������ ��� ��
			if (new_dist < dist[e]) { // ������ ���Ե� ��忡�� ���� ���� �� ��� �� �� ���� ��尡 �����Ѵٸ� ť�� �����Ѵ�.
				pq.push({ e, new_dist });
			}
		}
	}
	//show_1d_array(dist);
	cout << dist[dest] << "\n";


	return 0;
}*/