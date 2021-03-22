/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////
#define NOT_CHECKED 7

using Pos = pair<int, int>;

// ���� ��ü
struct Elem {
	int s, e, w;
	bool operator<(const Elem& arg) const {
		return this->w > arg.w;
	}

};

int N, M;
int offset[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};
vector<int> fu_set;


// ���� üũ
inline int check_range(int i, int j) {
	if (i<1 || i>N || j<1 || j>M) return 0;
	return 1;
}

void BFS(vector<vector<int>>& board, vector<vector<Pos>>& area) {
	int v_no = 0;
	vector<vector<int>> pushed(N + 1, vector<int>(M + 1, 0)); // 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// ���ο� ���� �߰��� ���
			if (!pushed[i][j] && board[i][j] == NOT_CHECKED) {
				v_no++;                         // �� ��ȣ
				area.push_back(vector<Pos>());  // �� ��ǥ ����

				// BFS
				queue<Pos> q;
				q.push({ i, j });
				pushed[i][j] = 1;

				while (!q.empty()) {
					Pos c_e = q.front();
					q.pop();

					board[c_e.first][c_e.second] = v_no;
					area[v_no].push_back(c_e);

					for (int k = 0; k < 4; k++) {
						int n_i = c_e.first + offset[k][0],
							n_j = c_e.second + offset[k][1];

						if (!check_range(n_i, n_j)) continue;

						if (!pushed[n_i][n_j] && board[n_i][n_j] == NOT_CHECKED) {
							q.push({ n_i, n_j });
							pushed[n_i][n_j] = 1;
						}

					}

				}

			}
		}
	}
	return;
}

void build_edge(vector<vector<int>>& board, int c_i, int c_j, priority_queue<Elem>& pq, int k) {
	int c_n = board[c_i][c_j]; // ���� �� ��ȣ Ȯ��
	int length = 0;
	while (1) {
		// ����ĭ Ȯ��
		c_i += offset[k][0];
		c_j += offset[k][1];

		// ���� �ʰ��� ��� ����
		if (!check_range(c_i, c_j)) return;

		if (board[c_i][c_j] == c_n) return; // �ڱ� ���� �ٽ� �ٸ��� ���� �� �����Ƿ� ����
		else if (board[c_i][c_j] == 0) length++; // �ٴ��̸� �ٸ��� ���� ���
		else { // �ٸ� ���� ����ģ ���, ������ ���� �ְ� ����
			if (length == 1) return; // �ٸ� ���̰� 1 ���ϸ� ����
			pq.push({ c_n, board[c_i][c_j], length });
			return;
		}

	}
}

void check_all_edges(vector<vector<int>>& board, vector<vector<Pos>>& area, priority_queue<Elem>& pq) {
	int V = area.size() - 1;
	for (int v = 1; v <= V; v++) { // ��� ���� ���ؼ� ���� ã��
		vector<Pos>& c_n = area[v];

		for (auto& e : c_n) { // �� ������ �ٴٷ� �̾����� ���� �� �� ã��
			int c_i = e.first, c_j = e.second;

			// �ش� ���Ұ� �ٴٿ� �´�� �ִ� ���, �ٸ� ���̿� �´�� �� ��ȣ�� ã�´�.
			for (int k = 0; k < 4; k++) {
				int a_i = c_i + offset[k][0],
					a_j = c_j + offset[k][1];

				if (!check_range(a_i, a_j)) continue; // ���� �ʰ��� ����

				// �ٴ��� ��� �ٸ� ���� �õ�
				if (board[a_i][a_j] == 0)
					build_edge(board, c_i, c_j, pq, k);
			}
		}
	}
	return;
}

int find(int n) {
	if (fu_set[n] == n) return n;
	else return fu_set[n] = find(fu_set[n]);
}

int shortest_path(int V, priority_queue<Elem>& pq) {
	// ��� ����
	int path_length = 0;

	// Ʈ�� �ʱ�ȭ
	fu_set = vector<int>(V + 1);
	for (int i = 0; i <= V; i++) fu_set[i] = i;

	// ũ�罺Į �˰��� ����
	int cnt = 0; // �߰��� ���� ����
	while (!pq.empty()) {
		Elem edge = pq.top();
		pq.pop();

		int pa = find(edge.s);
		int pb = find(edge.e);

		if (pa != pb) {
			cnt++;
			path_length += edge.w;
			fu_set[pb] = pa;
			if (cnt == V - 1) break;
		}
	}

	// ��� ������ �� �õ��ص� ������ �ȵǴ� ��� ����
	if (cnt != V - 1) return -1;
	else return path_length;

}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) board[i][j] = NOT_CHECKED;
		}
	}

	// BFS ���� �׸���
	vector<vector<Pos>> area(1, vector<Pos>()); // 1~V ������ ���� ��ǥ ����, area[0] : ����
	BFS(board, area); // �� ��ȣ �ޱ�鼭 ���� ��ǥ ����

	// ���� ã��
	priority_queue<Elem> pq;
	check_all_edges(board, area, pq);

	// ũ�罺Į ����
	int V = area.size() - 1;
	int answer = shortest_path(V, pq);

	cout << answer << "\n";

	return 0;
}*/