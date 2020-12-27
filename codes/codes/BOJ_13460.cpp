/*
// 실패
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

int answer = 11;
int offset[4][2] = { // 동서남북 이동 시 offset
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

int tilt(vector<vector<char>> & board, Pos & Red, Pos & Blue, Pos & goal, char color, int dir) { // 공위치/방향
	int isGoal = 0;
	Pos & cur_ball = color == 'R' ? Red : Blue;
	Pos & opposite_ball = color == 'R' ? Blue : Red;

	while (1) { // 끝까지 이동
		int next_i = cur_ball.first  + offset[dir][0],
			next_j = cur_ball.second + offset[dir][1]; // 다음 위치

		// 다음 칸이 벽이거나 다른 색 공, 이미 골인 경우 종료
		if (cur_ball.first == 0 || cur_ball.second == 0) break;
		if (board[next_i][next_j] == '#') break;
		if (opposite_ball.first  == next_i &&
			opposite_ball.second == next_j) break;

		// 골일 경우, 빈 칸 처리 후 종료
		if (board[next_i][next_j] == 'O') {
			cur_ball.first = 0, cur_ball.second = 0;
			isGoal = 1;
			break;
		}

		// 공 움직임
		else {
			cur_ball.first  = next_i;
			cur_ball.second = next_j;
		}
	}
	return isGoal;
}

 char what_first(Pos& Red, Pos& Blue, int d) {
	char first_move='R'; // 겹치지 않는다면, 빨강부터 시작

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
	// 초과 수행
	if (cnt > 10) return;

	// 상하좌우 모든 경우에 대해 seach
	Pos Red_backup = Red, Blue_backup = Blue;

	for (int d = 0; d < 4; d++) {
		char first_move = what_first(Red, Blue, d);
		char second_move = first_move == 'R' ? 'B' : 'R';

		Red = Red_backup;  // 해당 단계에서 원래 위치로 이동
		Blue = Blue_backup;

		int first_goal = tilt(board, Red, Blue, goal, first_move, d);
		int second_goal = tilt(board, Red, Blue, goal, second_move, d);

		if (first_move=='R') { // 첫 움직인 공이 빨간 공일 때
			if (second_goal) { // 파란공이 들어갔다면
				Red = Red_backup;
				Blue = Blue_backup;
				continue; // 실패
			}
			else if (first_goal) { // 빨간 공이 들어갔을 경우
				Red = Red_backup;
				Blue = Blue_backup;
				answer = answer < cnt ? answer : cnt;
				continue; // 성공
			}
			else { // 어떤 공도 들어가지 않은 경우
				solution(board, Red, Blue, goal, cnt + 1);
			}
		}
		else {
			if (first_goal) { // 파란공이 들어갔다면
				Red = Red_backup;
				Blue = Blue_backup;
				continue; // 실패
			}
			else if (second_goal) { // 빨간 공이 들어갔을 경우
				Red = Red_backup;
				Blue = Blue_backup;
				answer = answer < cnt ? answer : cnt;

				continue; // 성공
			}
			else { // 어떤 공도 들어가지 않은 경우
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
	vector<vector<char>> board(N); // 보드 초기화
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