/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int N, M, K;
int ans = -40000;
int offset[4][2] = {
	-1 ,0,
	1, 0,
	0, 1,
	0, -1
};

inline int checkAdj(int i, int j, vector<vector<int>>& checked) {
	for (int z = 0; z < 4; z++) {
		int n_i = i + offset[z][0];
		int n_j = j + offset[z][1];

		if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M) continue;

		if (checked[n_i][n_j]) return 0;

	}
	return 1;
}

void solution(int pi, int pj, vector<int>& arr, vector<vector<int>>& board, vector<vector<int>>& checked) {
	if (arr.size() == K) {
		int tmp_ans = 0;

		for (auto& e : arr)
			tmp_ans += e;

		ans = ans > tmp_ans ? ans : tmp_ans;
	}
	else {
		for (int i = pi; i < N; i++) {
			for (int j = (i == pi ? pj : 0); j < M; j++) {
				if (!checked[i][j] && checkAdj(i, j, checked)) {
					checked[i][j] = 1;
					arr.push_back(board[i][j]);

					solution(i, j, arr, board, checked);

					checked[i][j] = 0;
					arr.pop_back();

				}
			}
		}
	}
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];


	// K의 최대 합을 구한다. 
	vector<int> arr;
	vector<vector<int>> checked(N, vector<int>(M, 0));

	solution(0, 0, arr, board, checked);


	cout << ans << "\n";

	return 0;
}*/