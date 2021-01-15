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

#define FAR 99999999

int N, M, D;
int answer = 0;

struct Enemy {
	int i, j, d;
	Enemy(int _i = -1, int _j = -1, int _d = FAR) {
		i = _i, j = _j, d = _d;
	}
};

// ���� ���� üũ
int check_over(vector<vector<int>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) { // ���� ���� �����ϴ� ���
				return 1;
			}
		}
	}
	return 0; // ���� �������� �ʴ� ���
}

// ���忡�� �� ����
int kill(vector<vector<int>>& board, vector<int>& archer) {
	int killed = 0;
	vector<Enemy> enemy; // ���� ������ ��ġ

	// ���� ���� ��ġ ���ϱ�
	for (auto& arc : archer) {
		int a_i = N, a_j = arc; // �ü� ��ġ 
		Enemy e; // ���� ���� ��ġ 

		// ���� ��ġ �ľ��ϱ�(���� ����� �� �� ����)
		for (int c = a_j + D - 1; c >= a_j - D + 1; c--) { // �����ʺ��� �˻��� ���� ���ʿ� �ִ� �� ���
			for (int r = a_i - D; r < N; r++) {

				// ���� �ʰ� üũ
				if (r < 0 || c < 0 || c >= M)
					continue;

				// ������ �ִ� ���
				if (board[r][c] == 1) {
					int d = abs(a_i - r) + abs(a_j - c);

					if (d <= D && d <= e.d) { // D �Ÿ� ���� �ְ� ����� �������� ������ �ִٸ� ����
						e = Enemy(r, c, d);
					}
				}
			}
		}

		// ���� ���� �߰�
		if (e.d < FAR) enemy.push_back(e);
	}

	// �� ���̱�
	for (auto& ene : enemy) {
		if (board[ene.i][ene.j] == 1) { // �ٸ� �ü��� óġ�ϴ� ��츦 ����
			board[ene.i][ene.j] = 0;
			killed++;
		}
	}

	return killed;
}

// �� �����̱�
void move_enemy(vector<vector<int>>& board) {
	for (int j = 0; j < M; j++) {
		for (int i = N - 1; i > 0; i--) {
			board[i][j] = board[i - 1][j];
		}
	}
	fill(board[0].begin(), board[0].end(), 0);
}

void game(vector<vector<int>>& board, vector<int>& archer) {
	int temp_answer = 0;
	while (check_over(board)) {	// 1. ���� ���� Ȯ�� 
		// 2. �� ����
		temp_answer += kill(board, archer);

		// 3. �� �̵�
		move_enemy(board);
	}

	// ���� ����
	answer = answer > temp_answer ? answer : temp_answer;
	return;
}


void recursive(vector<vector<int>>& board, vector<int>& archer, int archer_pos) {
	// �ü� ��ġ�� ���� ��� ���� ����
	if (archer.size() == 3) {
		vector<vector<int>> new_board = board; // �������� �����Ѵ�.
		game(new_board, archer);

		return;
	}

	// ���� �ʰ� 
	if (archer_pos >= M) return;


	// 1. ���� ��ġ�� �ü� ��ġ
	archer.push_back(archer_pos);
	recursive(board, archer, archer_pos + 1);
	archer.pop_back();

	// 2. ���� ��ġ�� �ü� ���� ����.
	recursive(board, archer, archer_pos + 1);

	return;
}


void solution(vector<vector<int>>& board) {
	vector<int> archer; // �ü� �� ��ġ ����
	recursive(board, archer, 0);

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է� 
	cin >> N >> M >> D;
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// �ַ��
	solution(board);

	cout << answer << "\n";
	return 0;
}*/