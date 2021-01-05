/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////


int N;
int offset[4][2] = { // ���ϼ���
	1, 0,
	0, -1,
	-1, 0,
	0, 1
};
vector<vector<int>> board(101, vector<int>(101, 0)); // [0, 100] ����

void curve(int x, int y, int d, int g) {
	int c_e_x = x, c_e_y = y;	// ù ��
	vector<Pos> curve_pos;  // �巡�� Ŀ���� ��� ��

	// 0����
	board[c_e_x][c_e_y] = 1; // ù ��ġ

	int n_e_x = c_e_x + offset[d][0],
		n_e_y = c_e_y + offset[d][1];

	board[n_e_x][n_e_y] = 1; // ù ���� 

	curve_pos.push_back(Pos(c_e_x, c_e_y));
	curve_pos.push_back(Pos(n_e_x, n_e_y));

	// 1����~g����
	for (int cur_g = 1; cur_g <= g; cur_g++) {
		int len = curve_pos.size();
		Pos end_pos = curve_pos[len - 1]; // ������ ���Ҵ� �׻� �����̴�.

		// ������ �������� ��ȯ�� ��ǥ ����
		for (int i = len - 2; i >= 0; i--) { // ������ �׻� curve_pos ���� �α� ���� ���� ���� 
			// offset ���ϱ�
			int n_x_offset = curve_pos[i].first - end_pos.first,
				n_y_offset = curve_pos[i].second - end_pos.second;

			// offset 90�� ȸ��
			n_y_offset *= -1;
			swap(n_x_offset, n_y_offset);

			// 90�� ȸ�� �� ���ϱ�
			int n_x = end_pos.first + n_x_offset,
				n_y = end_pos.second + n_y_offset;

			// ���� ����
			board[n_x][n_y] = 1;

			// ȸ���� ��ǥ ����
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

		// Ŀ�� ����
		curve(x, y, d, g);


	}


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) std::cout << board[i][j] << " ";
		std::cout << "\n";
	}


	// ���簢�� üũ
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