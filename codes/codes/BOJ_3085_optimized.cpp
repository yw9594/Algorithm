/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int N;
int max_len = 1;

void checkMaxLen(const vector<vector<char>>& board, int idx, int opt) {
	if (opt == 0) {
		// 가로줄 최대 길이
		int len = 1;
		char color = board[idx][0]; // 첫 색상 저장
		for (int j = 1; j < N; j++) {
			if (board[idx][j] == color) { // 색이 이어지는 경우
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // 다른 색이 나타난 경우
				len = 1;
				color = board[idx][j];
			}
		}
	}
	else {
		// 세로줄 최대 길이
		int len = 1;
		char color = board[0][idx]; // 첫 색상 저장
		for (int i = 1; i < N; i++) {
			if (board[i][idx] == color) { // 색이 이어지는 경우
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // 다른 색이 나타난 경우
				len = 1;
				color = board[i][idx];
			}
		}

	}
}


void solution(vector<vector<char>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 가로 바꾸기
			swap(board[i][j], board[i][j + 1]); // 위치 바꾸기

			checkMaxLen(board, i, 0);
			checkMaxLen(board, j, 1);
			if (j + 1 < N)
				checkMaxLen(board, j + 1, 1);

			swap(board[i][j], board[i][j + 1]); // 되돌리기

			// 세로 바꾸기
			swap(board[i][j], board[i + 1][j]);

			checkMaxLen(board, j, 1);
			checkMaxLen(board, i, 0);
			if (i + 1 < N)
				checkMaxLen(board, i + 1, 0);

			swap(board[i][j], board[i + 1][j]);

		}
	}

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력 받기
	cin >> N;

	vector<vector<char>> board(N + 1, vector<char>(N + 1)); // 마지막 행/열의 정답 검사 시를 위한 더미 데이터

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 문제 해결
	solution(board);

	cout << max_len << "\n";

	return 0;
}*/