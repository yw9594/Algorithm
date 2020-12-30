/*#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, L, R;
long long int answer = 0LL;

int offset[4][2] = {
	0,1,
	1,0,
	0, -1,
	-1, 0
};

struct Elem {
	int i, j, p; // 국가 위치, 인구 수 
	Elem(int i = -1, int j = -1, int p = 0) {
		this->i = i;
		this->j = j;
		this->p = p;
	}
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	vector<vector<int>> board(N, vector<int>(N)); // board 생성

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	while (1) {
		long long int num_move = 0LL;
		vector<vector<int>> pushed(N, vector<int>(N, 0)); // board 생성

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!pushed[i][j]) { // 검사하지 않은 국가에 대해 인구이동
					vector<Elem> nations;
					queue<Elem> q;

					q.push(Elem(i, j, board[i][j]));
					pushed[i][j] = 1;

					// BFS
					while (!q.empty()) {
						Elem cur_elem = q.front();
						q.pop();

						nations.push_back(cur_elem);

						for (int k = 0; k < 4; k++) {
							int next_i = cur_elem.i + offset[k][0], next_j = cur_elem.j + offset[k][1];


							if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= N) continue; // 범위 초과

							int gap = abs((cur_elem.p - board[next_i][next_j]));

							if (!pushed[next_i][next_j] && (L <= gap && gap <= R)) {


								q.push(Elem(next_i, next_j, board[next_i][next_j]));
								pushed[next_i][next_j] = 1;
							}
						}
					}

					// 인구 이동
					int num_nations = nations.size();
					if (num_nations == 1) continue; // 연합이 없으므로 종료
					else { // 2개 이상 국가 연합 시
						int sum_p = 0;
						for (int k = 0; k < num_nations; k++) sum_p += nations[k].p;

						sum_p /= num_nations;

						for (int k = 0; k < num_nations; k++) board[nations[k].i][nations[k].j] = sum_p;

						num_move++;
					}

				}
			}
		}
		if (num_move == 0) break; // 해당 날짜에 이동 없음
		else  answer++;// += num_move;

	}

	cout << answer << "\n";


	return 0;
}*/