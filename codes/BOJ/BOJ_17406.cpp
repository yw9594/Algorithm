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

struct RInfo {
	int no;
	int i, j, s;

	bool operator<(RInfo& arg) {
		return this->no < arg.no;
	}
};

int N, M, K;

int check_answer(vector<vector<int>>& board) {
	int m_v = 21000000;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= M; j++) {
			temp += board[i][j];
		}

		m_v = m_v < temp ? m_v : temp;
	}
	return m_v;
}

vector<vector<int>> rotate_board(vector<vector<int>>  board, vector<RInfo>& r_info) {
	vector<vector<int>> new_board = board;
	for (auto& e : r_info) {
		int c_i = e.i, c_j = e.j, c_s = e.s;
		for (int s = e.s; s > 0; s--) {
			for (int j = c_j - s + 1; j <= c_j + s; j++) new_board[c_i - s][j] = board[c_i - s][j - 1]; // 상단
			for (int i = c_i - s + 1; i <= c_i + s; i++) new_board[i][c_j + s] = board[i - 1][c_j + s]; // 우측
			for (int j = c_j + s - 1; j >= c_j - s; j--) new_board[c_i + s][j] = board[c_i + s][j + 1]; // 하단
			for (int i = c_i + s - 1; i >= c_i - s; i--) new_board[i][c_j - s] = board[i + 1][c_j - s]; // 좌측

		}
		board = new_board;
	}
	return new_board;
}



int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	vector<vector<int>> board(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	vector<RInfo> r_info;
	for (int e = 0; e < K; e++) {
		int i, j, s;
		cin >> i >> j >> s;
		r_info.push_back({ e, i, j, s });
	}

	int answer = 21000000;
	do {
		// 원본 배열 유지 
		vector<vector<int>> new_board = rotate_board(board, r_info);


		// 배열 값 구하기
		int temp = check_answer(new_board);
		answer = answer < temp ? answer : temp;

	} while (next_permutation(r_info.begin(), r_info.end()));

	cout << answer << "\n";

	return 0;
}*/