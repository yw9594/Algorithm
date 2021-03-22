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
#define INF 92233720368

int N, M;
int start, dest;
long long int dist[1001];
vector<int> pushed;
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

	weight = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, INF));	// ����ġ �迭 �ʱ�ȭ
	matrix = vector<vector<int>>(N + 1, vector<int>()); // ���� ����Ʈ �ʱ�ȭ


	// �Է� �ޱ�
	for (int i = 1; i <= M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		weight[s][e] = w;		// ����ġ �迭
		matrix[s].push_back(e); // ���� ����Ʈ 
	}
	cin >> start >> dest; // �����/������




	// ���ͽ�Ʈ�� ����
	fill(dist, dist + 1001, INF);
	dist[start] = 0;
	pushed = vector<int>(N + 1, 0); // ��� ���տ� ���ԵǴ��� ���� üũ

	vector<int> path_set;
	int cur_node = start;
	pushed[cur_node] = 1;


	while (path_set.size() != N) {
		// ���� ���, ��� ���� ���� 
		path_set.push_back(cur_node);


		// ��� ���տ��� �� �� �ִ� ���, ��� ����
		for (auto& e : matrix[cur_node]) {
			dist[e] = (dist[e] <= weight[cur_node][e] + dist[cur_node]) ? dist[e] : weight[cur_node][e] + dist[cur_node];
		}


		// ���� ��� ���տ��� ��� ���տ� ���Ե��� ���� ��� ��, ���� ��� ����ġ ���� ���� ��� ����
		cur_node = 0; // �ּڰ��� ã�� ���� ���� ������ 
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