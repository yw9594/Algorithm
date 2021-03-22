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

	// ���� ã�� 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!pushed[i][j] && board[i][j] != E) { // ���� �˻簡 �ȵ� �ѿ䰡 �ִ� ���� �߰�
				char color = board[i][j];
				queue<Pos> q;   // BFS Queue
				vector<Pos> del; // �����ؾ��� ���� ��ġ

				// BFS ����
				q.push(Pos(i, j));
				pushed[i][j] = 1;

				while (!q.empty()) {
					Pos c_pos = q.front();
					q.pop();

					del.push_back(c_pos);

					for (int k = 0; k < 4; k++) {
						int n_i = c_pos.first + offset[k][0],
							n_j = c_pos.second + offset[k][1];

						if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M) continue; // ���� �ʰ� �� ó�� x
						if (!pushed[n_i][n_j] && board[n_i][n_j] == color) {
							q.push(Pos(n_i, n_j));
							pushed[n_i][n_j] = 1;
						}

					}
				}

				// ���� ����
				if (del.size() >= 4) { // ������ 4�� �̻��� ��츸 ����
					for (auto& e : del)	board[e.first][e.second] = E;
					is_boom = 1; // ������ �߻������Ƿ� 1 ����
				}
			}
		}
	}

	return is_boom;
}

// ��� �ѿ� ������
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

	// �Է�
	vector<vector<char>> board(N, vector<char>(M, E));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// �Ͷ߸��� ����
	while (1) {

		int is_boom = BFS(board);

		if (is_boom == 0) break; // �� �̻� ������ �ʴ´�.

		move_all(board);

		answer++;
	}

	cout << answer << "\n";

	return 0;
}*/