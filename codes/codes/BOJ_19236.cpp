/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

struct Fish {
	int no, dir;
};
struct Shark {
	int i, j, dir, eaten;
};
struct Pos {
	int i, j;
};

int answer = 0;
const Fish no_fish = { -1, -1 };
const Pos no_pos = { -1, -1 };

int offset[8][2] = { // 0~7 : ������ �ݽð� ����
	-1, 0,
	-1, -1,
	0, -1,
	1, -1,
	1, 0,
	1, 1,
	0, 1,
	-1, 1
};

// ���� üũ
int check_range(int i, int j) {
	if (i < 0 || i >= 4 || j < 0 || j >= 4) return 0;
	return 1;
}

int is_shark(Shark& shark, int i, int j) {
	if (shark.i == i && shark.j == j) return 0;
	return 1;
}

vector<Pos> make_fish_pos(vector<vector<Fish>>& board) {
	vector<Pos> fish_pos(17, no_pos);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int no = board[i][j].no,
				dir = board[i][j].dir;

			if (no == -1) continue;	 // ����Ⱑ ���� ��� ����

			fish_pos[no] = { i, j };

		}
	}
	return fish_pos;
}

void solution(vector<vector<Fish>>& board, Shark& shark) {
	vector<vector<Fish>> new_board = board;

	// ����� ��ġ �ľ�
	vector<Pos> fish_pos = make_fish_pos(board);

	// ����� �̵�
	for (int n = 1; n <= 16; n++) {
		int c_i = fish_pos[n].i,
			c_j = fish_pos[n].j;

		if (c_i == -1) continue; // ����Ⱑ ���� ��� ����

		for (int k = 0; k < 8; k++) {
			int c_dir = (new_board[c_i][c_j].dir + k) % 8; // ���� ����Ⱑ �ٶ󺸴� ������� �˻��Ѵ�.
			int n_i = c_i + offset[c_dir][0],
				n_j = c_j + offset[c_dir][1];

			if (check_range(n_i, n_j) && is_shark(shark, n_i, n_j)) { // ��踦 �Ѱų� ����ִ� ĭ�� �̵� �Ұ�

				if (new_board[n_i][n_j].no != -1) { // ������ ĭ�� ����Ⱑ �ִ� ���
					int n_no = new_board[n_i][n_j].no;
					fish_pos[n_no].i = c_i;				// ����� ��ġ ����
					fish_pos[n_no].j = c_j;
				}

				fish_pos[n].i = n_i;					// ����� ��ġ ����
				fish_pos[n].j = n_j;

				new_board[c_i][c_j].dir = c_dir;				// ���� ������� ���� ��ȯ
				swap(new_board[c_i][c_j], new_board[n_i][n_j]); // ���� ������ ������ ��ġ ��ȯ





				break;
			}
		}
	}

	// ��� �̵�
	bool is_eaten = false;
	for (int d = 1; d <= 3; d++) { // ���� ĭ ���� �ִ� 3ĭ���� ����Ⱑ ������ �� �ִ�.
		int n_i = shark.i + offset[shark.dir][0] * d,
			n_j = shark.j + offset[shark.dir][1] * d;

		if (check_range(n_i, n_j)) { // ���� ���� ���
			if (new_board[n_i][n_j].no != -1) { // ����Ⱑ �ִ� ���
				is_eaten = true;
				Shark  new_shark = { n_i, n_j, new_board[n_i][n_j].dir, shark.eaten + new_board[n_i][n_j].no };
				Fish old_fish = new_board[n_i][n_j];

				new_board[n_i][n_j] = no_fish;

				solution(new_board, new_shark);

				new_board[n_i][n_j] = old_fish;
			}
			else continue;
		}
		else break;
	}


	// �� ���� ����Ⱑ ���� ��� 
	if (!is_eaten)
		answer = answer > shark.eaten ? answer : shark.eaten;
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<Fish>> board(4, vector<Fish>(4, { -1, -1 }));	// �ٴ� ��

	// �Է�
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int no, dir;
			cin >> no >> dir;
			board[i][j] = { no, dir - 1 }; // ���� : dir-1
		}
	}

	// ���� Ǯ�� ����

	// (0,0)���� ����
	Shark shark = { 0, 0, board[0][0].dir, board[0][0].no };
	board[0][0] = no_fish;


	solution(board, shark);

	cout << answer << "\n";

	return 0;
}*/