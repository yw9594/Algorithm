/*#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

typedef pair<int, int> Pos;

int N, M, T;
int offset[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

void roll(vector<int>& row, int x, int d, int k) {
	int len = row.size();
	deque<int> q;

	for (auto& e : row)
		q.push_back(e);

	if (d == 0) {
		while (k--) {
			int f = q.back();
			q.pop_back();
			q.push_front(f);

		}
	}
	else {
		while (k--) {
			int f = q.front();
			q.pop_front();
			q.push_back(f);
		}
	}

	for (int i = 0; i < len; i++)
		row[i] = q[i];
	return;
}


void rotate_board(vector<vector<int>>& board, int x, int d, int k) {
	for (int n = 1; n <= N; n++)
		if (n % x == 0)
			roll(board[n], x, d, k);

	return;
}

void BSF(vector<vector<int>>& board) {
	vector<vector<int>> pushed(N + 1, vector<int>(M, 0));
	queue<Pos> del_list;

	for (int i = 1; i <= N; i++) { // 원판, 1:N
		for (int j = 0; j < M; j++) { // 숫자, 0:M-1
			if (!pushed[i][j] && board[i][j]) { // 아직 검사안한 숫자가 있는 경우
				queue<Pos> q;
				queue<Pos> temp_list;

				q.push(Pos(i, j));
				pushed[i][j] = 1;

				while (!q.empty()) {
					Pos cur_pos = q.front();
					q.pop();

					temp_list.push(cur_pos);

					for (int k = 0; k < 4; k++) {
						int next_i = cur_pos.first + offset[k][0],
							next_j = (cur_pos.second + offset[k][1] + M) % M; // 원형

						if (!(next_i >= 1 && next_i <= N && next_j >= 0 && next_j < M)) continue;

						if (!pushed[next_i][next_j] &&
							board[cur_pos.first][cur_pos.second] == board[next_i][next_j]) {

							q.push(Pos(next_i, next_j));
							pushed[next_i][next_j] = 1;
						}
					}
				}

				if (temp_list.size() > 1) { // 인접한 수가 2개 이상일 경우
					while (!temp_list.empty()) {
						del_list.push(temp_list.front());
						temp_list.pop();
					}
				}
			}
		}
	}

	// 인접 수 검사
	if (del_list.size() == 0) { // 인접한 수가 하나도 없는 경우 
		double s = 0.;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j]) {

					s += board[i][j];
					cnt++;
				}
			}
		}
		s /= cnt;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j]) {
					if (s > board[i][j]) board[i][j]++;
					else if (s < board[i][j]) board[i][j]--;
				}
			}
		}
	}
	else { // 인접한 수가 있는 경우
		while (!del_list.empty()) {
			Pos e = del_list.front();
			del_list.pop();

			board[e.first][e.second] = 0;
		}
	}

	return;
}

int main(void) {
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	vector<vector<int>> board(N + 1, vector<int>(M)); // board[0]:dummy
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	while (T--) {
		int x, d, k;
		cin >> x >> d >> k;

		// 회전
		rotate_board(board, x, d, k);

		// BFS
		BSF(board);
	}

	int s = 0;

	for (int i = 0; i <= N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j])
				s += board[i][j];

	cout << s << "\n";


	return 0;
}*/