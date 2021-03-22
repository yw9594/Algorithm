/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////
#define NOT_CHECKED 7

using Pos = pair<int, int>;

// 간선 객체
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


// 범위 체크
inline int check_range(int i, int j) {
	if (i<1 || i>N || j<1 || j>M) return 0;
	return 1;
}

void BFS(vector<vector<int>>& board, vector<vector<Pos>>& area) {
	int v_no = 0;
	vector<vector<int>> pushed(N + 1, vector<int>(M + 1, 0)); // 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// 새로운 섬을 발견한 경우
			if (!pushed[i][j] && board[i][j] == NOT_CHECKED) {
				v_no++;                         // 섬 번호
				area.push_back(vector<Pos>());  // 섬 좌표 지정

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
	int c_n = board[c_i][c_j]; // 현재 섬 번호 확인
	int length = 0;
	while (1) {
		// 다음칸 확인
		c_i += offset[k][0];
		c_j += offset[k][1];

		// 범위 초과일 경우 종료
		if (!check_range(c_i, c_j)) return;

		if (board[c_i][c_j] == c_n) return; // 자기 섬에 다시 다리를 놓을 순 없으므로 종료
		else if (board[c_i][c_j] == 0) length++; // 바다이면 다리를 놓고 계속
		else { // 다른 섬을 마주친 경우, 간선을 힙에 넣고 종료
			if (length == 1) return; // 다리 길이가 1 이하면 종료
			pq.push({ c_n, board[c_i][c_j], length });
			return;
		}

	}
}

void check_all_edges(vector<vector<int>>& board, vector<vector<Pos>>& area, priority_queue<Elem>& pq) {
	int V = area.size() - 1;
	for (int v = 1; v <= V; v++) { // 모든 섬에 대해서 간선 찾기
		vector<Pos>& c_n = area[v];

		for (auto& e : c_n) { // 한 섬에서 바다로 이어지는 방향 중 섬 찾기
			int c_i = e.first, c_j = e.second;

			// 해당 원소가 바다와 맞닿아 있는 경우, 다리 길이와 맞닿는 섬 번호를 찾는다.
			for (int k = 0; k < 4; k++) {
				int a_i = c_i + offset[k][0],
					a_j = c_j + offset[k][1];

				if (!check_range(a_i, a_j)) continue; // 범위 초과시 무시

				// 바다인 경우 다리 놓기 시도
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
	// 경로 길이
	int path_length = 0;

	// 트리 초기화
	fu_set = vector<int>(V + 1);
	for (int i = 0; i <= V; i++) fu_set[i] = i;

	// 크루스칼 알고리즘 시작
	int cnt = 0; // 추가된 간선 개수
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

	// 모든 간선을 다 시도해도 연결이 안되는 경우 종료
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

	// BFS 영역 그리기
	vector<vector<Pos>> area(1, vector<Pos>()); // 1~V 섬까지 섬의 좌표 모음, area[0] : 더미
	BFS(board, area); // 섬 번호 메기면서 섬의 좌표 저장

	// 간선 찾기
	priority_queue<Elem> pq;
	check_all_edges(board, area, pq);

	// 크루스칼 적용
	int V = area.size() - 1;
	int answer = shortest_path(V, pq);

	cout << answer << "\n";

	return 0;
}*/