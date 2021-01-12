/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////
int N, L, answer = 0;

int check_range(int& i, int& j) {
	if (i < 0 || i >= N || j < 0 || j >= N) return 0;
	return 1;
}

void check_route(vector<vector<int>>& board) {
	// ���� �� ���� ���ϱ�
	for (int r = 0; r < N; r++) {
		int flag = true;	       // �� ���� ����
		vector<int> checked(N, 0); // ���� ��ġ ����

		for (int c = 0; c < N - 1; c++) {
			// ���� ĭ ���̰� ���� ���
			if (board[r][c] == board[r][c + 1]) continue;

			// ���� ĭ ���̰� �ٸ� ���
			else {
				// 1 �̻� ���̳� ��� �Ұ���
				if (abs(board[r][c] - board[r][c + 1]) > 1) {
					flag = false;
					break;
				}
				// 1��ŭ ���� ���� ���
				else {
					int low, high;

					// ���� ĭ�� �� ���� ���
					if (board[r][c] < board[r][c + 1])
						low = c - L + 1, high = c;

					// ���� ĭ�� �� ���� ���
					else
						low = c + 1, high = c + L;

					// ������ ����� ��� ���� �Ұ�
					if (!check_range(low, high)) {
						flag = false;
						break;
					}
					// ���θ� ���� �� �ִ� ��� 
					else {
						// ���� ���� �� üũ 
						int height = board[r][low];
						if (checked[low]) {
							flag = false;
							break;
						}
						for (int k = low + 1; k <= high && flag; k++)
							if (checked[k] || board[r][k] != height) // �̹� ���ΰ� ��ġ�Ǿ��ְų� ���̰� �ٸ� ���
								flag = false;


						// ���� ��ġ
						if (flag)
							for (int k = low; k <= high; k++) checked[k] = 1;

						// ���� ��ġ �Ұ��� 
						else break;

					}
				}
			}
		}
		// ���� �ִ� ��� �߰�
		if (flag) answer++;
	}

	// ���� �� ���� ���ϱ�
	for (int c = 0; c < N; c++) {
		int flag = true;	       // �� ���� ����
		vector<int> checked(N, 0); // ���� ��ġ ����

		for (int r = 0; r < N - 1; r++) {
			// ���� ĭ ���̰� ���� ���
			if (board[r][c] == board[r + 1][c]) continue;

			// ���� ĭ ���̰� �ٸ� ���
			else {
				// 1 �̻� ���̳� ��� �Ұ���
				if (abs(board[r][c] - board[r + 1][c]) > 1) {
					flag = false;
					break;
				}
				// 1��ŭ ���� ���� ���
				else {
					int low, high;

					// ���� ĭ�� �� ���� ���
					if (board[r][c] < board[r + 1][c])
						low = r - L + 1, high = r;

					// ���� ĭ�� �� ���� ���
					else
						low = r + 1, high = r + L;

					// ������ ����� ��� ���� �Ұ�
					if (!check_range(low, high)) {
						flag = false;
						break;
					}
					// ���θ� ���� �� �ִ� ��� 
					else {
						// ���� ���� �� üũ 
						int height = board[low][c];
						if (checked[low]) {
							flag = false;
							break;
						}
						for (int k = low + 1; k <= high && flag; k++) {
							if (checked[k] || board[k][c] != height) {// �̹� ���ΰ� ��ġ�Ǿ��ְų� ���̰� �ٸ� ���
								flag = false;
							}
						}


						// ���� ��ġ
						if (flag)
							for (int k = low; k <= high; k++) checked[k] = 1;

						// ���� ��ġ �Ұ��� 
						else {
							break;
						}

					}
				}
			}
		}
		// ���� �ִ� ��� �߰�
		if (flag) answer++;
	}
	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];


	check_route(board);

	cout << answer << "\n";


	return 0;
}*/