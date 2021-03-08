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

void checkMaxLen(const vector<vector<char>>& board) {
	// 가로 최대 길이
	for (int i = 0; i < N; i++) {
		int len = 1;
		char color = board[i][0]; // 첫 색상 저장
		for (int j = 1; j < N; j++) {
			if (board[i][j] == color) { // 색이 이어지는 경우
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // 다른 색이 나타난 경우
				len = 1;
				color = board[i][j];
			}
		}
	}

	// 세로 최대 길이
	for (int j = 0; j < N; j++) {
		int len = 1;
		char color = board[0][j]; // 첫 색상 저장
		for (int i = 1; i < N; i++) {
			if (board[i][j] == color) { // 색이 이어지는 경우
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // 다른 색이 나타난 경우
				len = 1;
				color = board[i][j];
			}
		}
	}
}


void solution(vector<vector<char>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 가로 바꾸기
			swap(board[i][j], board[i][j + 1]); // 위치 바꾸기

			checkMaxLen(board);

			swap(board[i][j], board[i][j + 1]); // 되돌리기

			// 세로 바꾸기
			swap(board[i][j], board[i + 1][j]);

			checkMaxLen(board);

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

	vector<vector<char>> board(N + 1, vector<char>(N + 1, 'a')); // 마지막 행/열의 정답 검사 시를 위한 더미 데이터

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