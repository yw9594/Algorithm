/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int N;
int max_len = 1;

void checkMaxLen(const vector<vector<char>>& board, int idx, int opt) {
	if (opt == 0) {
		// ������ �ִ� ����
		int len = 1;
		char color = board[idx][0]; // ù ���� ����
		for (int j = 1; j < N; j++) {
			if (board[idx][j] == color) { // ���� �̾����� ���
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // �ٸ� ���� ��Ÿ�� ���
				len = 1;
				color = board[idx][j];
			}
		}
	}
	else {
		// ������ �ִ� ����
		int len = 1;
		char color = board[0][idx]; // ù ���� ����
		for (int i = 1; i < N; i++) {
			if (board[i][idx] == color) { // ���� �̾����� ���
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // �ٸ� ���� ��Ÿ�� ���
				len = 1;
				color = board[i][idx];
			}
		}

	}
}


void solution(vector<vector<char>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ���� �ٲٱ�
			swap(board[i][j], board[i][j + 1]); // ��ġ �ٲٱ�

			checkMaxLen(board, i, 0);
			checkMaxLen(board, j, 1);
			if (j + 1 < N)
				checkMaxLen(board, j + 1, 1);

			swap(board[i][j], board[i][j + 1]); // �ǵ�����

			// ���� �ٲٱ�
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

	// �Է� �ޱ�
	cin >> N;

	vector<vector<char>> board(N + 1, vector<char>(N + 1)); // ������ ��/���� ���� �˻� �ø� ���� ���� ������

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// ���� �ذ�
	solution(board);

	cout << max_len << "\n";

	return 0;
}*/