/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

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
int fishman = 0;					// 낚시꾼 위치
vector<Shark> fished;				// 잡은 상어들 
vector<vector<int>> direction(5, vector<int>()); //  상어 이동 배열

inline int chech_range(int& i, int& j) {
	if (i<1 || i>R || j<1 || j>C) return 0;
	return 1;
}


// 1마리 상어를 이동, d, j 변화
void move(Shark& shark) {
	int cnt = shark.s;
	int k, pos;

	vector<int>& move_offset = direction[shark.d];

	if (shark.d == 1 || shark.d == 2) { // 위 or 아래
		for (k = 0; k < R; k++) // 상어의 위치에 맞는 인덱스 구하기
			if (move_offset[k] == shark.i)
				break;

		pos = (k + shark.s) % (2 * R - 2); // 나머지 값으로 위치 측정 
		shark.i = move_offset[pos];
		if (pos >= R) shark.d = shark.d == 1 ? 2 : 1; // 만약 범위를 넘어섰다면 방향 전환

	}
	else { // 오른쪽 or 왼쪽
		for (k = 0; k < C; k++) // 상어의 위치에 맞는 인덱스 구하기
			if (move_offset[k] == shark.j)
				break;

		pos = (k + shark.s) % (2 * C - 2); // 나머지 값으로 위치 측정 
		shark.j = move_offset[pos];
		if (pos >= C) shark.d = shark.d == 3 ? 4 : 3; // 만약 범위를 넘어섰다면 방향 전환
	}


	return;
}

void move_and_eat(vector<vector<Shark>>& new_board, vector<Shark>& pos_shark) {
	for (auto& shark : pos_shark) {
		// 상어 이동
		move(shark);

		// 최종 이동 칸에 상어가 있는 경우
		if (shark.w > new_board[shark.i][shark.j].w) // 잡아먹고 자리 차지
			new_board[shark.i][shark.j] = shark;
	}
}

void move_shark(vector<vector<Shark>>& board) {
	vector<Shark> pos_shark; // 최초 상어 위치 기록
	// 모든 상어 위치 파악
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (board[i][j].w != 0) {
				pos_shark.push_back(board[i][j]);
			}
		}
	}

	// (동시에) 모든 상어 움직이기 or 먹기 
	vector<vector<Shark>> new_board(R + 1, vector<Shark>(C + 1, Shark())); // 움직인 이후의 새로운 바다
	move_and_eat(new_board, pos_shark); // 움직이기 & 먹기

	// 새 보드 복사
	board = new_board;
	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> R >> C >> M;
	vector<vector<Shark>> board(R + 1, vector<Shark>(C + 1, Shark())); // 상어의 몸무게가 0이면 빈 칸
	while (M--) {
		int i, j, s, w, d; // d:1234 -> 위아오왼
		cin >> i >> j >> s >> d >> w;

		board[i][j] = Shark(i, j, s, d, w); // 상어 삽입
	}

	// 상어 이동 배열 생성
	// 위
	for (int i = R; i >= 1; i--) direction[1].push_back(i);
	for (int i = 2; i <= R - 1; i++) direction[1].push_back(i);

	// 아래
	for (int i = 1; i <= R; i++) direction[2].push_back(i);
	for (int i = R - 1; i >= 2; i--) direction[2].push_back(i);

	// 오른쪽
	for (int i = 1; i <= C; i++) direction[3].push_back(i);
	for (int i = C - 1; i >= 2; i--) direction[3].push_back(i);


	// 왼쪽
	for (int i = C; i >= 1; i--) direction[4].push_back(i);
	for (int i = 2; i <= C - 1; i++) direction[4].push_back(i);

	// 낚시 시작
	while (fishman < C) {
		// 어부 이동
		fishman++;
		for (int i = 1; i <= R; i++) {
			if (board[i][fishman].w != 0) { // 상어가 있는 경우 
				fished.push_back(board[i][fishman]);   // 잡은 상어 그물 추가
				board[i][fishman] = Shark();			// 상어 제거

				break; // 땅에서 가장 가까운 상어만 제거
			}
		}

		// 상어 이동 및 제거
		move_shark(board);
	}

	// 상어 무게 총합 구하기
	int answer = 0;
	for (auto& shark : fished)
		answer += shark.w;

	cout << answer << "\n";


	return 0;
}*/