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

int N, M, answer = -1;
int offset[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

struct Elem {
	int cnt;
	int r_i, r_j, b_i, b_j;
	Elem(int _cnt, int _r_i, int _r_j, int _b_i, int _b_j) {
		cnt = _cnt;
		r_i = _r_i;
		r_j = _r_j;
		b_i = _b_i;
		b_j = _b_j;
	}
	bool is_same_pos() {
		return (r_i == b_i) && (r_j == b_j);
	}
};


void move_ball(vector<vector<char>>& board, int& b_i, int& b_j, int k) {
	while (1) {
		b_i += offset[k][0];
		b_j += offset[k][1];

		switch (board[b_i][b_j]) {
		case '#': // 벽인 경우 후퇴
			b_i -= offset[k][0];
			b_j -= offset[k][1];
			return;
		case 'O': // 골인 경우 중지
			return;
		}
	}
	return;
}




int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);


	// 입력
	cin >> N >> M;
	Pos r_pos, b_pos, g_pos;
	vector<vector<char>> board(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char cur_ch;
			cin >> cur_ch;

			switch (cur_ch) {
			case '#':
			case '.':
				board[i][j] = cur_ch; // 벽 또는 빈공간
				break;
			case 'R': // 빨간 공
				r_pos.first = i;
				r_pos.second = j;
				board[i][j] = '.';
				break;
			case 'B': // 파란 공
				b_pos.first = i;
				b_pos.second = j;
				board[i][j] = '.';
				break;
			case 'O': // 홀 위치
				g_pos.first = i;
				g_pos.second = j;
				board[i][j] = 'O';
				break;
			}
		}
	}

	// BFS 시작
	int pushed[10][10][10][10] = { 0 };
	queue<Elem> q;
	q.push(Elem(0, r_pos.first, r_pos.second, b_pos.first, b_pos.second));
	pushed[r_pos.first][r_pos.second][b_pos.first][b_pos.second] = 1;

	while (!q.empty()) {
		Elem c_e = q.front();
		q.pop();


		// cout << c_e.r_i << " " << c_e.r_j << " " << c_e.b_i << " " << c_e.b_j << "\n";

		if (c_e.r_i == g_pos.first && c_e.r_j == g_pos.second) {
			answer = c_e.cnt;
			break; // 최소 움직임을 구하므로 BFS로 첫 골 발견 시 중지한다.
		}

		for (int k = 0; k < 4; k++) {
			Elem n_e = c_e;
			n_e.cnt++;

			move_ball(board, n_e.r_i, n_e.r_j, k); // 빨간공 굴리기
			move_ball(board, n_e.b_i, n_e.b_j, k); // 파랑공 굴리기

			if (n_e.b_i == g_pos.first && n_e.b_j == g_pos.second) // 파란공이 들어간 경우 답이 될 수 없다.
				continue;

			if (n_e.is_same_pos()) { // 겹치는 경우
				switch (k) { // 처음 위치를 고려해 공 되돌림
				case 0:
					c_e.b_j > c_e.r_j ? n_e.r_j-- : n_e.b_j--; break;
				case 1:
					c_e.b_j > c_e.r_j ? n_e.b_j++ : n_e.r_j++; break;
				case 2:
					c_e.b_i > c_e.r_i ? n_e.r_i-- : n_e.b_i--; break;
				case 3:
					c_e.b_i > c_e.r_i ? n_e.b_i++ : n_e.r_i++; break;
				}
			}

			if (!pushed[n_e.r_i][n_e.r_j][n_e.b_i][n_e.b_j]) {
				q.push(n_e);
				pushed[n_e.r_i][n_e.r_j][n_e.b_i][n_e.b_j] = 1;
			}
		}

	}

	cout << (answer > 10 ? -1 : answer) << "\n";

	return 0;
}*/