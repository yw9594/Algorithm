/*#include <iostream>
#include <vector>

#define WALL 6
#define MARK 7

using namespace std;

int N, M;
int answer = 9999999;

typedef pair<int, int> Pos;

void cover(vector<vector<int>>& board, vector<Pos>& cctv, int idx, int dir) {
	Pos camera_pos = cctv[idx];

	if (dir == 0) {
		for (int j = camera_pos.second + 1; j < M; j++) {
			if (board[camera_pos.first][j] == 0)
				board[camera_pos.first][j] = MARK;
			else if (board[camera_pos.first][j] == WALL)
				break;
		}
	}
	else if (dir == 1) {
		for (int j = camera_pos.second - 1; j >= 0; j--) {
			if (board[camera_pos.first][j] == 0)
				board[camera_pos.first][j] = MARK;
			else if (board[camera_pos.first][j] == WALL)
				break;
		}
	}
	else if (dir == 2) {
		for (int i = camera_pos.first + 1; i < N; i++) {
			if (board[i][camera_pos.second] == 0)
				board[i][camera_pos.second] = MARK;
			else if (board[i][camera_pos.second] == WALL)
				break;
		}
	}
	else {
		for (int i = camera_pos.first - 1; i >= 0; i--) {
			if (board[i][camera_pos.second] == 0)
				board[i][camera_pos.second] = MARK;
			else if (board[i][camera_pos.second] == WALL)
				break;
		}
	}

	return;
}

void look(vector<vector<int>>& board, vector<Pos>& cctv, int idx, int dir) {
	int camera_type = board[cctv[idx].first][cctv[idx].second];

	if (camera_type == 1) {
		cover(board, cctv, idx, dir);
	}
	else if (camera_type == 2) {
		if (dir == 0 || dir == 1) {
			cover(board, cctv, idx, 0);
			cover(board, cctv, idx, 1);
		}
		else {
			cover(board, cctv, idx, 2);
			cover(board, cctv, idx, 3);
		}
	}
	else if (camera_type == 3) {
		if (dir == 0) {
			cover(board, cctv, idx, 0);
			cover(board, cctv, idx, 3);
		}
		else if (dir == 1) {
			cover(board, cctv, idx, 1);
			cover(board, cctv, idx, 2);
		}
		else if (dir == 2) {
			cover(board, cctv, idx, 2);
			cover(board, cctv, idx, 0);
		}
		else {
			cover(board, cctv, idx, 3);
			cover(board, cctv, idx, 1);
		}

	}
	else if (camera_type == 4) {
		if (dir == 0) {
			cover(board, cctv, idx, 0);
			cover(board, cctv, idx, 2);
			cover(board, cctv, idx, 3);
		}
		else if (dir == 1) {
			cover(board, cctv, idx, 1);
			cover(board, cctv, idx, 2);
			cover(board, cctv, idx, 3);
		}
		else if (dir == 2) {
			cover(board, cctv, idx, 0);
			cover(board, cctv, idx, 1);
			cover(board, cctv, idx, 2);
		}
		else {
			cover(board, cctv, idx, 0);
			cover(board, cctv, idx, 1);
			cover(board, cctv, idx, 3);
		}

	}
	else if (camera_type == 5) {
		for (int k = 0; k < 4; k++)
			cover(board, cctv, idx, k);
	}

}


void solution(vector<vector<int>>& board, vector<Pos>& cctv, int idx) {
	if (cctv.size() == idx) {
		// 공백체크 및 정답 갱신
		int temp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0)
					temp++;
			}
		}
		cout << "=================\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}


		answer = answer < temp ? answer : temp;
		return;
	}

	for (int d = 0; d < 4; d++) { // 카메라 회전, 0123:동서남북 
		vector<vector<int>> new_board = board;
		look(new_board, cctv, idx, d);
		solution(new_board, cctv, idx + 1);
	}

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> board(N);
	for (auto& p : board) p = vector<int>(M);


	vector<Pos> cctv;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] && board[i][j] != 6) cctv.push_back(Pos(i, j));
		}
	}
	solution(board, cctv, 0);
	cout << answer << "\n";

	return 0;
}*/