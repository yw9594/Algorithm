/*#include <iostream>
#include <vector>
#include <queue>

#define SEA 0

using namespace std;



int N, M, answer = 0;
int offset[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};

typedef pair<int, int> Pos;

struct Ice {
	int i, j, m; // 위치, 바다면
	Ice(int i = -1, int j = -1, int m = -1) {
		this->i = i;
		this->j = j;
		this->m = m;
	}
};

int sea_num(vector<vector<int>>& board, int c_i, int c_j) {
	int num_of_sea = 0;
	for (int k = 0; k < 4; k++) {
		int n_i = c_i + offset[k][0],
			n_j = c_j + offset[k][1];

		if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M) continue;
		else if (board[n_i][n_j] == SEA) num_of_sea++;
	}
	return num_of_sea;
}

int BFS(vector<vector<int>>& board, queue<Ice>& melt_list) {
	int area = 0;
	vector<vector<int>> pushed(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0 && !pushed[i][j]) { // 빙산이 있는데 아직 검사를 안한 경우
				area++;

				queue<Ice> q;

				Ice init_ice = Ice(i, j, sea_num(board, i, j));

				q.push(init_ice);
				pushed[i][j] = 1;

				while (!q.empty()) {
					Ice cur_ice = q.front();
					q.pop();

					melt_list.push(cur_ice);

					for (int k = 0; k < 4; k++) {
						int n_i = cur_ice.i + offset[k][0],
							n_j = cur_ice.j + offset[k][1];

						if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M) continue;
						if (!pushed[n_i][n_j] && board[n_i][n_j] != SEA) {
							q.push(Ice(n_i, n_j, sea_num(board, n_i, n_j)));
							pushed[n_i][n_j] = 1;
						}
					}
				}
			}
		}
	}

	return area;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	// solution
	while (1) {
		queue<Ice> melt_list; // 빙산 정보 저장

		// BFS
		int area = BFS(board, melt_list);

		if (area == 0) { // 1. 빙산이 2덩어리로 분할되기 전 다 녹는 경우
			answer = 0;
			break;
		}
		else if (area >= 2)  // 2. 2개 이상 분할 
			break;
		else { // 3. 빙산 녹이기
			while (!melt_list.empty()) {
				Ice cur_ice = melt_list.front();
				melt_list.pop();

				board[cur_ice.i][cur_ice.j] -= cur_ice.m;
				if (board[cur_ice.i][cur_ice.j] < 0)
					board[cur_ice.i][cur_ice.j] = 0;
			}
		}

		// 시간 증가
		answer++;
	}


	cout << answer << "\n";

	return 0;
}*/