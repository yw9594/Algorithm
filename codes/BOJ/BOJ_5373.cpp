// 실패 
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int rotate_side[6][4] = { // 중심 면 별 회전에 영향을 받는 면
	1,2,3,4,
	0,4,5,2,
	0,1,5,3,
	0,2,5,4,
	0,3,5,1,
	3,2,1,4
};

void init_cube(vector<vector<vector<char>>>& cube) {
	char color[6] = { 'w', 'o', 'b', 'r', 'g', 'y' };

	for (int c = 0; c < 6; c++) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cube[c][i][j] = color[c];
	}
}



void rotate_cube(vector<vector<vector<char>>>& cube, char side, char dir) {
	int center_side;

	// 중심 면 설정
	switch (side) {
	case 'U':center_side = 0;	break;
	case 'D':center_side = 5;	break;
	case 'F':center_side = 3;	break;
	case 'B':center_side = 1;	break;
	case 'L':center_side = 4;	break;
	case 'R':center_side = 2;	break;
	}

	// 중심면 회전
	int c_i = 1, c_j = 1; // 중심 축
	vector<vector<char>> changed_center = cube[center_side];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int o_i = c_i - i, o_j = c_j - j;

			// 방향 고려
			if (dir == '-') o_j *= -1;
			else o_i *= -1;

			changed_center[c_i + o_i][c_j + o_j] = cube[center_side][i][j];


		}
	}
	cube[center_side] = changed_center;


	// 옆면 회전
	if (dir == '-') {
		vector<vector<char>> u_side = cube[rotate_side[center_side][0]];
		vector<vector<char>> r_side = cube[rotate_side[center_side][1]];
		vector<vector<char>> d_side = cube[rotate_side[center_side][2]];
		vector<vector<char>> l_side = cube[rotate_side[center_side][3]];


		u_side[2][0] = cube[rotate_side[center_side][1]][0][0];
		u_side[2][1] = cube[rotate_side[center_side][1]][1][0];
		u_side[2][2] = cube[rotate_side[center_side][1]][2][0];

		l_side[0][2] = cube[rotate_side[center_side][0]][2][2];
		l_side[1][2] = cube[rotate_side[center_side][0]][2][1];
		l_side[2][2] = cube[rotate_side[center_side][0]][2][0];

		d_side[0][0] = cube[rotate_side[center_side][3]][0][2];
		d_side[0][1] = cube[rotate_side[center_side][3]][1][2];
		d_side[0][2] = cube[rotate_side[center_side][3]][2][2];

		r_side[0][0] = cube[rotate_side[center_side][2]][0][2];
		r_side[1][0] = cube[rotate_side[center_side][2]][0][1];
		r_side[2][0] = cube[rotate_side[center_side][2]][0][0];


		cube[rotate_side[center_side][0]] = u_side;
		cube[rotate_side[center_side][1]] = r_side;
		cube[rotate_side[center_side][2]] = d_side;
		cube[rotate_side[center_side][3]] = l_side;
	}
	else {
		// 돌아간 면
		vector<vector<char>> u_side = cube[rotate_side[center_side][0]];
		vector<vector<char>> r_side = cube[rotate_side[center_side][1]];
		vector<vector<char>> d_side = cube[rotate_side[center_side][2]];
		vector<vector<char>> l_side = cube[rotate_side[center_side][3]];


		u_side[2][0] = cube[rotate_side[center_side][3]][2][2];
		u_side[2][1] = cube[rotate_side[center_side][3]][1][2];
		u_side[2][2] = cube[rotate_side[center_side][3]][0][2];

		r_side[0][0] = cube[rotate_side[center_side][0]][2][0];
		r_side[1][0] = cube[rotate_side[center_side][0]][2][1];
		r_side[2][0] = cube[rotate_side[center_side][0]][2][2];

		d_side[0][0] = cube[rotate_side[center_side][1]][2][0];
		d_side[0][1] = cube[rotate_side[center_side][1]][1][0];
		d_side[0][2] = cube[rotate_side[center_side][1]][0][0];

		l_side[0][2] = cube[rotate_side[center_side][2]][0][0];
		l_side[1][2] = cube[rotate_side[center_side][2]][0][1];
		l_side[2][2] = cube[rotate_side[center_side][2]][0][2];

		cube[rotate_side[center_side][0]] = u_side;
		cube[rotate_side[center_side][1]] = r_side;
		cube[rotate_side[center_side][2]] = d_side;
		cube[rotate_side[center_side][3]] = l_side;
	}

	return;
}



int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		show_line();
		// 초기 큐브 생성
		vector<vector<vector<char>>> cube(6, vector<vector<char>>(3, vector<char>(3))); // 큐브	
		init_cube(cube);

		// 입력
		int cnt;
		cin >> cnt;
		while (cnt--) {
			char side, dir;

			cin >> side >> dir;

			rotate_cube(cube, side, dir);
		}


		// 출력
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << "\n";
		}
		
	}

	return 0;
}*/