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
		case '#': // ���� ��� ����
			b_i -= offset[k][0];
			b_j -= offset[k][1];
			return;
		case 'O': // ���� ��� ����
			return;
		}
	}
	return;
}




int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);


	// �Է�
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
				board[i][j] = cur_ch; // �� �Ǵ� �����
				break;
			case 'R': // ���� ��
				r_pos.first = i;
				r_pos.second = j;
				board[i][j] = '.';
				break;
			case 'B': // �Ķ� ��
				b_pos.first = i;
				b_pos.second = j;
				board[i][j] = '.';
				break;
			case 'O': // Ȧ ��ġ
				g_pos.first = i;
				g_pos.second = j;
				board[i][j] = 'O';
				break;
			}
		}
	}

	// BFS ����
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
			break; // �ּ� �������� ���ϹǷ� BFS�� ù �� �߰� �� �����Ѵ�.
		}

		for (int k = 0; k < 4; k++) {
			Elem n_e = c_e;
			n_e.cnt++;

			move_ball(board, n_e.r_i, n_e.r_j, k); // ������ ������
			move_ball(board, n_e.b_i, n_e.b_j, k); // �Ķ��� ������

			if (n_e.b_i == g_pos.first && n_e.b_j == g_pos.second) // �Ķ����� �� ��� ���� �� �� ����.
				continue;

			if (n_e.is_same_pos()) { // ��ġ�� ���
				switch (k) { // ó�� ��ġ�� ����� �� �ǵ���
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