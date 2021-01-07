/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int N, M, answer = 0;
int offset[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};
inline int check_ranage(int& i, int& j) {
	if (i < 0 || i >= N || j < 0 || j >= M) return 0;
	return 1;
}

// �ܺ� ���� üũ 
void check_outside(vector<vector<int>>& board, vector<vector<int>>& pushed) {
	queue<Pos> q;

	q.push(Pos(0, 0)); // ���� �ڸ��� ġ� �������� �ʴ´�.
	pushed[0][0] = 1;

	while (!q.empty()) {
		Pos cur_pos = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int n_i = cur_pos.first + offset[k][0],
				n_j = cur_pos.second + offset[k][1];

			if (check_ranage(n_i, n_j) && !pushed[n_i][n_j] && board[n_i][n_j] == 0) { // ����, Ǫ����, ���� ����
				q.push(Pos(n_i, n_j));
				pushed[n_i][n_j] = 1;
			}

		}
	}
	return;
}

// ��� ġ�� ���� 
void check_cheese(vector<vector<int>>& board, vector<Pos>& cheese) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j]) {
				if (board[i][j] == 1) {
					cheese.push_back(Pos(i, j));
				}
			}
		}
	}
}

// ���̱� 
int melt(vector<vector<int>>& board, vector<vector<int>>& outside, vector<Pos>& cheese) {
	int num_of_cheese = cheese.size();

	for (auto& e : cheese) {
		int num_outside = 0;
		Pos& cur_pos = e;

		// �����¿�, �ܺ� ���Ⱑ 2 �̻��̸� ��´�.
		for (int k = 0; k < 4; k++) {
			int n_i = cur_pos.first + offset[k][0],
				n_j = cur_pos.second + offset[k][1];

			if (board[n_i][n_j] == 0 && outside[n_i][n_j]) {
				num_outside++;
			}
		}

		if (num_outside >= 2) {
			board[cur_pos.first][cur_pos.second] = 0;
			num_of_cheese--;
		}
	}
	return num_of_cheese;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	// ġ�� ���̱� ����
	while (1) {
		int num_of_cheese;
		vector<Pos> cheese;									// ġ�� ��ġ
		vector<vector<int>> outside(N, vector<int>(M, 0)); // �ܺ� ���� üũ

		answer++;

		check_outside(board, outside);

		check_cheese(board, cheese);

		num_of_cheese = melt(board, outside, cheese);

		if (num_of_cheese == 0) break;
	}
	cout << answer << "\n";

	return 0;
}*/