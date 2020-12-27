/*
// ����
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

int answer = 11;
int offset[4][2] = { // �������� �̵� �� offset
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int tilt(vector<vector<char>> & board, Pos & Red, Pos & Blue, Pos & goal, char color, int dir) { // ����ġ/����
	int isGoal = 0;
	Pos & cur_ball = color == 'R' ? Red : Blue;
	Pos & opposite_ball = color == 'R' ? Blue : Red;

	while (1) { // ������ �̵�
		int next_i = cur_ball.first  + offset[dir][0],
			next_j = cur_ball.second + offset[dir][1]; // ���� ��ġ

		// ���� ĭ�� ���̰ų� �ٸ� �� ��, �̹� ���� ��� ����
		if (cur_ball.first == 0 || cur_ball.second == 0) break;
		if (board[next_i][next_j] == '#') break;
		if (opposite_ball.first  == next_i &&
			opposite_ball.second == next_j) break;

		// ���� ���, �� ĭ ó�� �� ����
		if (board[next_i][next_j] == 'O') {
			cur_ball.first = 0, cur_ball.second = 0;
			isGoal = 1;
			break;
		}

		// �� ������
		else {
			cur_ball.first  = next_i;
			cur_ball.second = next_j;
		}
	}
	return isGoal;
}

 char what_first(Pos& Red, Pos& Blue, int d) {
	char first_move='R'; // ��ġ�� �ʴ´ٸ�, �������� ����

	switch (d) {
	case 0:
		if (Red.first == Blue.first) {
			if (Red.second > Blue.second) first_move = 'R';
			else first_move = 'B';
		}
		break;
	case 1:
		if (Red.first == Blue.first) {
			if (Red.second > Blue.second) first_move = 'B';
			else first_move = 'R';
		}
		break;
	case 2:
		if (Red.second == Blue.second) {
			if (Red.first > Blue.first) first_move = 'R';
			else first_move = 'B';
		}
		break;
	case 3:
		if (Red.second == Blue.second) {
			if (Red.first > Blue.first) first_move = 'B';
			else first_move = 'R';
		}
		break;

	}
	return first_move;
}

void solution(vector<vector<char>>& board, Pos& Red, Pos& Blue, Pos& goal, int cnt=1) {
	// �ʰ� ����
	if (cnt > 10) return;

	// �����¿� ��� ��쿡 ���� seach
	Pos Red_backup = Red, Blue_backup = Blue;

	for (int d = 0; d < 4; d++) {
		char first_move = what_first(Red, Blue, d);
		char second_move = first_move == 'R' ? 'B' : 'R';

		Red = Red_backup;  // �ش� �ܰ迡�� ���� ��ġ�� �̵�
		Blue = Blue_backup;

		int first_goal = tilt(board, Red, Blue, goal, first_move, d);
		int second_goal = tilt(board, Red, Blue, goal, second_move, d);

		if (first_move=='R') { // ù ������ ���� ���� ���� ��
			if (second_goal) { // �Ķ����� ���ٸ�
				Red = Red_backup;
				Blue = Blue_backup;
				continue; // ����
			}
			else if (first_goal) { // ���� ���� ���� ���
				Red = Red_backup;
				Blue = Blue_backup;
				answer = answer < cnt ? answer : cnt;
				continue; // ����
			}
			else { // � ���� ���� ���� ���
				solution(board, Red, Blue, goal, cnt + 1);
			}
		}
		else {
			if (first_goal) { // �Ķ����� ���ٸ�
				Red = Red_backup;
				Blue = Blue_backup;
				continue; // ����
			}
			else if (second_goal) { // ���� ���� ���� ���
				Red = Red_backup;
				Blue = Blue_backup;
				answer = answer < cnt ? answer : cnt;

				continue; // ����
			}
			else { // � ���� ���� ���� ���
				solution(board, Red, Blue, goal, cnt + 1);
			}
		}

	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	//std::istream::sync_with_stdio(false);
	//cin.tie(NULL);

	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<char>> board(N); // ���� �ʱ�ȭ
	for (auto& a : board) a = vector<char>(M);

	Pos Red, Blue, Goal;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			scanf(" %c", &c);
			if (c == 'R') {
				Red = Pos(i, j);
				c = '.';
			}
			else if (c == 'B') {
				Blue = Pos(i, j);
				c = '.';
			}
			else if (c == 'O') Goal = Pos(i, j);
			board[i][j] = c;
		}
	}

	solution(board, Red, Blue, Goal);
	answer = answer != 11 ? answer : -1;
	cout << answer << "\n";



	return 0;
}*/