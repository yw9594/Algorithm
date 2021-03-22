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

#define FAR 99999999

int N, M, D;
int answer = 0;

struct Enemy {
	int i, j, d;
	Enemy(int _i = -1, int _j = -1, int _d = FAR) {
		i = _i, j = _j, d = _d;
	}
};

// 게임 오버 체크
int check_over(vector<vector<int>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) { // 아직 적이 존재하는 경우
				return 1;
			}
		}
	}
	return 0; // 적이 존재하지 않는 경우
}

// 보드에서 적 제거
int kill(vector<vector<int>>& board, vector<int>& archer) {
	int killed = 0;
	vector<Enemy> enemy; // 사살될 적군의 위치

	// 죽을 적의 위치 구하기
	for (auto& arc : archer) {
		int a_i = N, a_j = arc; // 궁수 위치 
		Enemy e; // 사살될 적군 위치 

		// 적군 위치 파악하기(가장 가까운 적 중 왼쪽)
		for (int c = a_j + D - 1; c >= a_j - D + 1; c--) { // 오른쪽부터 검사해 가장 왼쪽에 있는 적 대상
			for (int r = a_i - D; r < N; r++) {

				// 범위 초과 체크
				if (r < 0 || c < 0 || c >= M)
					continue;

				// 적군이 있는 경우
				if (board[r][c] == 1) {
					int d = abs(a_i - r) + abs(a_j - c);

					if (d <= D && d <= e.d) { // D 거리 내에 있고 저장된 적군보다 가까이 있다면 갱신
						e = Enemy(r, c, d);
					}
				}
			}
		}

		// 사살될 적군 추가
		if (e.d < FAR) enemy.push_back(e);
	}

	// 적 죽이기
	for (auto& ene : enemy) {
		if (board[ene.i][ene.j] == 1) { // 다른 궁수가 처치하는 경우를 제외
			board[ene.i][ene.j] = 0;
			killed++;
		}
	}

	return killed;
}

// 적 움직이기
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
	while (check_over(board)) {	// 1. 게임 오버 확인 
		// 2. 적 제거
		temp_answer += kill(board, archer);

		// 3. 적 이동
		move_enemy(board);
	}

	// 정답 갱신
	answer = answer > temp_answer ? answer : temp_answer;
	return;
}


void recursive(vector<vector<int>>& board, vector<int>& archer, int archer_pos) {
	// 궁수 배치가 끝난 경우 게임 수행
	if (archer.size() == 3) {
		vector<vector<int>> new_board = board; // 원본판은 유지한다.
		game(new_board, archer);

		return;
	}

	// 범위 초과 
	if (archer_pos >= M) return;


	// 1. 현재 위치에 궁수 배치
	archer.push_back(archer_pos);
	recursive(board, archer, archer_pos + 1);
	archer.pop_back();

	// 2. 현재 위치에 궁수 넣지 않음.
	recursive(board, archer, archer_pos + 1);

	return;
}


void solution(vector<vector<int>>& board) {
	vector<int> archer; // 궁수 열 위치 저장
	recursive(board, archer, 0);

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력 
	cin >> N >> M >> D;
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// 솔루션
	solution(board);

	cout << answer << "\n";
	return 0;
}*/