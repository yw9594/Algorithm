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

#define E '.'
#define R 'R'
#define G 'G'
#define B 'B'
#define Y 'Y'
#define P 'P'

#define N 12
#define M 6

int answer = 0;
int offset[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int BFS(vector<vector<char>>& board) {
	int is_boom = 0;
	vector<vector<int>> pushed(N, vector<int>(M, 0));

	// 영역 찾기 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!pushed[i][j] && board[i][j] != E) { // 아직 검사가 안된 뿌요가 있는 영역 발견
				char color = board[i][j];
				queue<Pos> q;   // BFS Queue
				vector<Pos> del; // 삭제해야할 원소 위치

				// BFS 수행
				q.push(Pos(i, j));
				pushed[i][j] = 1;

				while (!q.empty()) {
					Pos c_pos = q.front();
					q.pop();

					del.push_back(c_pos);

					for (int k = 0; k < 4; k++) {
						int n_i = c_pos.first + offset[k][0],
							n_j = c_pos.second + offset[k][1];

						if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M) continue; // 범위 초과 시 처리 x
						if (!pushed[n_i][n_j] && board[n_i][n_j] == color) {
							q.push(Pos(n_i, n_j));
							pushed[n_i][n_j] = 1;
						}

					}
				}

				// 삭제 수행
				if (del.size() >= 4) { // 영역이 4개 이상인 경우만 제거
					for (auto& e : del)	board[e.first][e.second] = E;
					is_boom = 1; // 삭제가 발생했으므로 1 저장
				}
			}
		}
	}

	return is_boom;
}

// 모든 뿌요 내리기
void move_all(vector<vector<char>>& board) {
	for (int j = 0; j < M; j++) {
		for (int i = N - 1; i > 0; i--) {
			if (board[i][j] == E) {
				for (int k = i - 1; k >= 0; k--) {
					if (board[k][j] != E) {
						swap(board[i][j], board[k][j]);
						break;
					}
				}
			}
		}
	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	vector<vector<char>> board(N, vector<char>(M, E));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// 터뜨리기 시작
	while (1) {

		int is_boom = BFS(board);

		if (is_boom == 0) break; // 더 이상 터지지 않는다.

		move_all(board);

		answer++;
	}

	cout << answer << "\n";

	return 0;
}*/