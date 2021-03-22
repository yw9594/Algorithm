/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////


int N;
int offset[4][2] = { // 동북서남
	1, 0,
	0, -1,
	-1, 0,
	0, 1
};
vector<vector<int>> board(101, vector<int>(101, 0)); // [0, 100] 격자

void curve(int x, int y, int d, int g) {
	int c_e_x = x, c_e_y = y;	// 첫 점
	vector<Pos> curve_pos;  // 드래곤 커브의 모든 점

	// 0세대
	board[c_e_x][c_e_y] = 1; // 첫 위치

	int n_e_x = c_e_x + offset[d][0],
		n_e_y = c_e_y + offset[d][1];

	board[n_e_x][n_e_y] = 1; // 첫 끝점 

	curve_pos.push_back(Pos(c_e_x, c_e_y));
	curve_pos.push_back(Pos(n_e_x, n_e_y));

	// 1세대~g세대
	for (int cur_g = 1; cur_g <= g; cur_g++) {
		int len = curve_pos.size();
		Pos end_pos = curve_pos[len - 1]; // 마지막 원소는 항상 끝점이다.

		// 끝점을 기준으로 변환된 좌표 저장
		for (int i = len - 2; i >= 0; i--) { // 끝점을 항상 curve_pos 끝에 두기 위해 역순 저장 
			// offset 구하기
			int n_x_offset = curve_pos[i].first - end_pos.first,
				n_y_offset = curve_pos[i].second - end_pos.second;

			// offset 90도 회전
			n_y_offset *= -1;
			swap(n_x_offset, n_y_offset);

			// 90도 회전 점 구하기
			int n_x = end_pos.first + n_x_offset,
				n_y = end_pos.second + n_y_offset;

			// 보드 대입
			board[n_x][n_y] = 1;

			// 회전된 좌표 삽입
			curve_pos.push_back(Pos(n_x, n_y));
		}
	}

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		// 커브 생성
		curve(x, y, d, g);


	}


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) std::cout << board[i][j] << " ";
		std::cout << "\n";
	}


	// 정사각형 체크
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
				answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}*/