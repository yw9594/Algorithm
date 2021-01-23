/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;


/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////
#define INF 9876543210

using LL = long long int;
typedef pair<int, LL> Pos;

struct Elem {
	int n;
	LL w; // ��� ��ȣ, ��� ��
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
	dist = vector<LL>(N + 1, INF); // ����ġ�� �����ϴ� ��������Ʈ 
	matrix = vector<vector<Pos>>(N + 1, vector<Pos>()); // ����ġ�� �����ϴ� ��������Ʈ 

	// �Է�
	while (M--) {
		int s, e, w;
		cin >> s >> e >> w;
		matrix[s].push_back({ e, w });
	}
	cin >> start >> dest;


	// ���ͽ�Ʈ��
	priority_queue<Elem> pq;
	pq.push({ start, 0 }); // ���۳��� ������տ� �����Ѵ�.
	dist[start] = 0;

	while (!pq.empty()) {
		Elem cur_node = pq.top();
		pq.pop();

		// ���� ��庸�� �̹� ã�� ������� �� ���� ��� ���� ��δ� �����Ѵ�. 
		if (dist[cur_node.n] < cur_node.w)
			continue;

		// ������տ� ���Ե��� ���� ���ҵ� �߿��� �������� �� �۾����� ������ ��� �ִ´�.
		for (auto& e : matrix[cur_node.n]) {
			LL new_weight = dist[cur_node.n] + e.second; // ���� ��带 ���� ��� e�� ���� ��� ���� ��
			if (new_weight < dist[e.first]) {
				pq.push({ e.first, new_weight });
				dist[e.first] = new_weight;
			}
		}

	}


	cout << dist[dest] << "\n";

	return 0;
}*/