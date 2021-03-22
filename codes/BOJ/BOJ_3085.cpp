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

void checkMaxLen(const vector<vector<char>>& board) {
	// ���� �ִ� ����
	for (int i = 0; i < N; i++) {
		int len = 1;
		char color = board[i][0]; // ù ���� ����
		for (int j = 1; j < N; j++) {
			if (board[i][j] == color) { // ���� �̾����� ���
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // �ٸ� ���� ��Ÿ�� ���
				len = 1;
				color = board[i][j];
			}
		}
	}

	// ���� �ִ� ����
	for (int j = 0; j < N; j++) {
		int len = 1;
		char color = board[0][j]; // ù ���� ����
		for (int i = 1; i < N; i++) {
			if (board[i][j] == color) { // ���� �̾����� ���
				len++;
				max_len = max_len > len ? max_len : len;
			}
			else { // �ٸ� ���� ��Ÿ�� ���
				len = 1;
				color = board[i][j];
			}
		}
	}
}


void solution(vector<vector<char>>& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ���� �ٲٱ�
			swap(board[i][j], board[i][j + 1]); // ��ġ �ٲٱ�

			checkMaxLen(board);

			swap(board[i][j], board[i][j + 1]); // �ǵ�����

			// ���� �ٲٱ�
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

	// �Է� �ޱ�
	cin >> N;

	vector<vector<char>> board(N + 1, vector<char>(N + 1, 'a')); // ������ ��/���� ���� �˻� �ø� ���� ���� ������

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