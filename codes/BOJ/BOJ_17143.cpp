/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

struct Shark {
	int i, j, s, w, d;
	Shark(int i = 0, int j = 0, int s = 0, int d = -1, int w = 0) {
		this->i = i;
		this->j = j;
		this->w = w;
		this->d = d;
		this->s = s;
	}
};

int R, C, M;
int fishman = 0;					// ���ò� ��ġ
vector<Shark> fished;				// ���� ���� 
vector<vector<int>> direction(5, vector<int>()); //  ��� �̵� �迭

inline int chech_range(int& i, int& j) {
	if (i<1 || i>R || j<1 || j>C) return 0;
	return 1;
}


// 1���� �� �̵�, d, j ��ȭ
void move(Shark& shark) {
	int cnt = shark.s;
	int k, pos;

	vector<int>& move_offset = direction[shark.d];

	if (shark.d == 1 || shark.d == 2) { // �� or �Ʒ�
		for (k = 0; k < R; k++) // ����� ��ġ�� �´� �ε��� ���ϱ�
			if (move_offset[k] == shark.i)
				break;

		pos = (k + shark.s) % (2 * R - 2); // ������ ������ ��ġ ���� 
		shark.i = move_offset[pos];
		if (pos >= R) shark.d = shark.d == 1 ? 2 : 1; // ���� ������ �Ѿ�ٸ� ���� ��ȯ

	}
	else { // ������ or ����
		for (k = 0; k < C; k++) // ����� ��ġ�� �´� �ε��� ���ϱ�
			if (move_offset[k] == shark.j)
				break;

		pos = (k + shark.s) % (2 * C - 2); // ������ ������ ��ġ ���� 
		shark.j = move_offset[pos];
		if (pos >= C) shark.d = shark.d == 3 ? 4 : 3; // ���� ������ �Ѿ�ٸ� ���� ��ȯ
	}


	return;
}

void move_and_eat(vector<vector<Shark>>& new_board, vector<Shark>& pos_shark) {
	for (auto& shark : pos_shark) {
		// ��� �̵�
		move(shark);

		// ���� �̵� ĭ�� �� �ִ� ���
		if (shark.w > new_board[shark.i][shark.j].w) // ��Ƹ԰� �ڸ� ����
			new_board[shark.i][shark.j] = shark;
	}
}

void move_shark(vector<vector<Shark>>& board) {
	vector<Shark> pos_shark; // ���� ��� ��ġ ���
	// ��� ��� ��ġ �ľ�
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j].w != 0) {
				pos_shark.push_back(board[i][j]);
			}
		}
	}

	// (���ÿ�) ��� ��� �����̱� or �Ա� 
	vector<vector<Shark>> new_board(R + 1, vector<Shark>(C + 1, Shark())); // ������ ������ ���ο� �ٴ�
	move_and_eat(new_board, pos_shark); // �����̱� & �Ա�

	// �� ���� ����
	board = new_board;
	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	cin >> R >> C >> M;
	vector<vector<Shark>> board(R + 1, vector<Shark>(C + 1, Shark())); // ����� �����԰� 0�̸� �� ĭ
	while (M--) {
		int i, j, s, w, d; // d:1234 -> ���ƿ���
		cin >> i >> j >> s >> d >> w;

		board[i][j] = Shark(i, j, s, d, w); // ��� ����
	}

	// ��� �̵� �迭 ����
	// ��
	for (int i = R; i >= 1; i--) direction[1].push_back(i);
	for (int i = 2; i <= R - 1; i++) direction[1].push_back(i);

	// �Ʒ�
	for (int i = 1; i <= R; i++) direction[2].push_back(i);
	for (int i = R - 1; i >= 2; i--) direction[2].push_back(i);

	// ������
	for (int i = 1; i <= C; i++) direction[3].push_back(i);
	for (int i = C - 1; i >= 2; i--) direction[3].push_back(i);


	// ����
	for (int i = C; i >= 1; i--) direction[4].push_back(i);
	for (int i = 2; i <= C - 1; i++) direction[4].push_back(i);

	// ���� ����
	while (fishman < C) {
		// ��� �̵�
		fishman++;
		for (int i = 1; i <= R; i++) {
			if (board[i][fishman].w != 0) { // �� �ִ� ��� 
				fished.push_back(board[i][fishman]);   // ���� ��� �׹� �߰�
				board[i][fishman] = Shark();			// ��� ����

				break; // ������ ���� ����� �� ����
			}
		}

		// ��� �̵� �� ����
		move_shark(board);
	}

	// ��� ���� ���� ���ϱ�
	int answer = 0;
	for (auto& shark : fished)
		answer += shark.w;

	cout << answer << "\n";


	return 0;
}*/