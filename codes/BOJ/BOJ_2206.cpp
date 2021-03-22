/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////



int N, M;
const int MAX = 210000000;
int offset[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};


struct Elem {
	int i, j, p, b;
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력
	cin >> N >> M;
	vector<vector<char>> board(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int answer = MAX;
	int pushed[1000][1000][2] = { 0, }; // i, j, b // 부숴서 도달하는 경우 역시 상태로 취급한다.

	queue<Elem> q;
	q.push({ 0, 0, 1, 0 });
	pushed[0][0][0] = 1;

	while (!q.empty()) {
		Elem c_e = q.front();
		q.pop();

		if (c_e.i == N - 1 && c_e.j == M - 1) {
			answer = answer < c_e.p ? answer : c_e.p;
		}

		for (int k = 0; k < 4; k++) {
			int n_i = c_e.i + offset[k][0],
				n_j = c_e.j + offset[k][1];

			if (n_i < 0 || n_j < 0 || n_i >= N || n_j >= M) continue;


			if (!pushed[n_i][n_j][c_e.b]) {
				if (board[n_i][n_j] == '0') {
					q.push({ n_i, n_j, c_e.p + 1, c_e.b }); // 빈 공간인 경우
					pushed[n_i][n_j][c_e.b] = 1;
				}
				else if (board[n_i][n_j] == '1' && c_e.b == 0) { // 벽을 한 번 부술 수 있는 경우
					q.push({ n_i, n_j, c_e.p + 1, 1 });
					pushed[n_i][n_j][c_e.b] = 1;
				}
				// 나머지는 벽이면서 한 번 뚫고 지나온 경우이므로 더 이상 나아갈 수 없다.
			}
		}
	}

	cout << (answer == MAX ? -1 : answer) << "\n";

	return 0;
}*/