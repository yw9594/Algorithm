/* 라이브러리 & 메소드
// Headers
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

// input
std::istream>::sync_with_stdio(false);
cin.tie(NULL);
*/
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 99999999

struct Pos {
	int i, j; // 현재 위치
	int d;    // 기준점으로부터 거리
};

struct Taxi {
	int i, j; // 현재 위치
	int f;    // 연료
};

struct Tile {
	int type;		// 0, 1, 2 : 빈공간, 벽, 손님
	int client_no;  // 손님일 경우 손님 번호
	int dest_i, dest_j;     // 손님일 경우 목적지
};

int N, M, F;
int ans = 0;
vector<vector<Tile>> board;

int offset[4][2] = {
	-1,0,
	1, 0,
	0, -1,
	0, 1
};

inline bool check(Pos& next_pos, Pos& next_client_pos) {
	if (next_pos.i<1 || next_pos.i>N || next_pos.j<1 || next_pos.j>N) return false;
	if (next_pos.d > next_client_pos.d) return false; // 이미 찾은 최단 손님보다 거리가 클 경우, 불필요
	return true;
}

inline bool check(Pos& next_pos) {
	if (next_pos.i<1 || next_pos.i>N || next_pos.j<1 || next_pos.j>N) return false;
	return true;
}

bool move(Taxi& taxi) {

	// 최소 거리 손님 찾기
	queue<Pos> q;
	vector<vector<int>> pushed(N + 1, vector<int>(N + 1, 0));

	q.push({ taxi.i, taxi.j, 0 });
	pushed[taxi.i][taxi.j] = 1;

	Pos next_client_pos = { -1, -1, MAX }; // 다음 손님의 위치 정보
	while (!q.empty()) {
		Pos cur_pos = q.front();
		q.pop();

		//cout << cur_pos.i << " " << cur_pos.j << " " << cur_pos.d << "-\n";


		if (board[cur_pos.i][cur_pos.j].type == 2) {
			if (cur_pos.d == next_client_pos.d) {		// 거리가 같은 경우, 행과 열이 더 작은 순
				if (cur_pos.i == next_client_pos.i)
					next_client_pos = (cur_pos.j < next_client_pos.j) ? cur_pos : next_client_pos;
				else
					next_client_pos = (cur_pos.i < next_client_pos.i) ? cur_pos : next_client_pos;
			}
			else if (cur_pos.d > next_client_pos.d) // 최단 거리가 아니므로 종료
				break;
			else // BFS는 최단 거리 순으로 방문하므로 그냥 삽입
				next_client_pos = cur_pos;
		}

		for (int k = 0; k < 4; k++) {
			Pos next_pos = { cur_pos.i + offset[k][0],
							 cur_pos.j + offset[k][1],
							 cur_pos.d + 1 };

			if (check(next_pos, next_client_pos) &&  // 경계 및 d 검사
				board[next_pos.i][next_pos.j].type != 1 &&  // 벽 검사
				!pushed[next_pos.i][next_pos.j]) {          // 푸쉬 여부 검사


				q.push(next_pos);
				pushed[next_pos.i][next_pos.j] = 1;
			}
		}
	}
	// 유효성 검사
	if (next_client_pos.i == -1 ||	// 손님이 존재하지 않는 경우
		next_client_pos.d > taxi.f  // 손님은 찾았지만 연료가 부족한 경우
		) return false;



	// 택시, 손님 위치로 이동
	Tile cur_client = board[next_client_pos.i][next_client_pos.j];				// 다음 손님 위치
	board[next_client_pos.i][next_client_pos.j] = { 0, -1, -1, -1 };			// 손님 Tile -> 빈 공간 Tile
	taxi = { next_client_pos.i, next_client_pos.j, taxi.f - next_client_pos.d };  // 택시 상태 갱신



	// 택시, 손님의 목적지로 이동
	queue<Pos> q2;
	vector<vector<int>> pushed2(N + 1, vector<int>(N + 1, 0));

	q2.push({ taxi.i, taxi.j, 0 });
	pushed2[taxi.i][taxi.j] = 1;

	Pos next_dest_pos = { -1, -1, -1 }; // 소비되는 연료량

	while (!q2.empty()) {
		Pos cur_pos = q2.front();
		q2.pop();

		// cout << cur_pos.i << " " << cur_pos.j << " " << cur_pos.d << "--\n";


		if (cur_pos.i == cur_client.dest_i && cur_pos.j == cur_client.dest_j) {
			next_dest_pos = cur_pos;
			break;
		}

		for (int k = 0; k < 4; k++) {
			Pos next_pos = { cur_pos.i + offset[k][0],
							 cur_pos.j + offset[k][1],
							 cur_pos.d + 1 };

			if (check(next_pos) &&                          // 경계 검사
				board[next_pos.i][next_pos.j].type != 1 &&  // 벽 검사
				!pushed2[next_pos.i][next_pos.j]) {          // 푸쉬 여부 검사
				q2.push(next_pos);
				pushed2[next_pos.i][next_pos.j] = 1;
			}
		}
	}

	// 유효성 검사
	if (next_dest_pos.i == -1 ||		// 목적지를 못찾은 경우
		next_dest_pos.d > taxi.f)		// 연료가 모자라는 경우
		return false;

	// 택시 상태 갱신
	taxi = { next_dest_pos.i, next_dest_pos.j, taxi.f + next_dest_pos.d }; // 소모한 연료의 2배로 증가

	return true;
}

int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> N >> M >> F;

	board = vector<vector<Tile>>(N + 1, vector<Tile>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int type;
			cin >> type;
			board[i][j] = { type, -1, -1, -1 };
		}
	}

	int start_i, start_j;
	cin >> start_i >> start_j;

	for (int i = 0; i < M; i++) {
		int c_i, c_j, d_i, d_j;
		cin >> c_i >> c_j >> d_i >> d_j;
		board[c_i][c_j] = { 2, i, d_i, d_j }; // 손님 정보
	}

	// 문제 해결
	Taxi taxi = { start_i, start_j, F };
	int m = 0;
	for (; m < M; m++) {
		// 최소 거리 승객 찾고 목적지로 이동하기 
		int flag = move(taxi); // 성공 시 true 반환
		if (!flag)
			break;
	}

	ans = m == M ? taxi.f : -1;

	cout << ans << "\n";

	return 0;
}*/