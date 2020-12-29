/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int answer = 0LL;
int offset[4][2] = { // ��������
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};


void move_and_merge(vector<vector<int>>& board, int dir) {

	switch (dir) {
	case 0: // ��
		for (int i = 0; i < N; i++) {
			int idx = N - 1; // ���ڰ� �� ��ġ
			queue<int> q;
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}

			while (!q.empty()) {
				int num = q.front();
				q.pop();

				if (board[i][idx] == 0) // �� ĭ�� ���
					board[i][idx] = num;
				else if (board[i][idx] == num) { // ��ĥ �� �ִ� ��� 
					board[i][idx] *= 2;
					idx--;
				}
				else { // �ٸ� ���
					board[i][--idx] = num;
				}
			}


		}
		break;
	case 1: // ��
		for (int j = 0; j < N; j++) {
			int idx = N - 1; // ���ڰ� �� ��ġ
			queue<int> q;
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}

			while (!q.empty()) {
				int num = q.front();
				q.pop();

				if (board[idx][j] == 0) // �� ĭ�� ���
					board[idx][j] = num;
				else if (board[idx][j] == num) { // ��ĥ �� �ִ� ��� 
					board[idx][j] *= 2;
					idx--;
				}
				else { // �ٸ� ���
					board[--idx][j] = num;
				}
			}
		}
		break;
	case 2: // ��
		for (int i = 0; i < N; i++) {
			int idx = 0; // ���ڰ� �� ��ġ
			queue<int> q;
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}

			while (!q.empty()) {
				int num = q.front();
				q.pop();

				if (board[i][idx] == 0) // �� ĭ�� ���
					board[i][idx] = num;
				else if (board[i][idx] == num) { // ��ĥ �� �ִ� ��� 
					board[i][idx] *= 2;
					idx++;
				}
				else { // �ٸ� ���
					board[i][++idx] = num;
				}
			}


		}
		break;
	case 3: // ��
		for (int j = 0; j < N; j++) {
			int idx = 0; // ���ڰ� �� ��ġ
			queue<int> q;
			for (int i = 0; i < N; i++) {
				if (board[i][j] != 0) {
					q.push(board[i][j]);
					board[i][j] = 0;
				}
			}

			while (!q.empty()) {
				int num = q.front();
				q.pop();

				if (board[idx][j] == 0) // �� ĭ�� ���
					board[idx][j] = num;
				else if (board[idx][j] == num) { // ��ĥ �� �ִ� ��� 
					board[idx][j] *= 2;
					idx++;
				}
				else { // �ٸ� ���
					board[++idx][j] = num;
				}
			}
		}
		break;
	}
	return;
}

int get_max_score(vector<vector<int>>& board) {
	int max_score = 0LL;
	for (auto& p : board)
		for (auto& val : p)
			max_score = max_score > val ? max_score : val;
	return max_score;
}

void solution(vector<vector<int>>& board, int cnt) {
	if (cnt == 6) {
		// get max score
		int temp = get_max_score(board);


		if (temp >= answer) {
			answer = temp;
		}
		return;
	}


	for (int d = 0; d < 4; d++) {
		// move & merge	
		vector<vector<int>> next_board = board; //  ������ �� ����
		move_and_merge(next_board, d); // ����̱�
		solution(next_board, cnt + 1);
	}
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<vector<int>> board(N);
	for (auto& p : board) p = vector<int>(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];


	solution(board, 1);

	cout << answer << "\n";

	return 0;
}*/