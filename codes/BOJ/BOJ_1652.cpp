/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans_r, ans_c;
int checked[100][100] = { 0 };
int N;



int main(void) {
	freopen("input.txt", "r", stdin);
	//std::istream::sync_with_stdio(false);
	//cin.tie(NULL);

	scanf("%d", &N);
	vector<vector<char>> board(N);
	for (auto& p : board) p = vector<char>(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c; scanf(" %c", &c);
			board[i][j] = c;
		}
	}

	// 1. 행 검사 
	fill(&checked[0][0], &checked[N - 1][N], 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (board[i][j] == '.' && board[i][j + 1] == '.') {
				if (checked[i][j] == 0) ans_r++;
				checked[i][j] = checked[i][j + 1] = 1;

			}
		}
	}

	// 2. 열 검사 
	fill(&checked[0][0], &checked[N - 1][N], 0);
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			if (board[i][j] == '.' && board[i + 1][j] == '.') {
				if (checked[i][j] == 0) ans_c++;
				checked[i][j] = checked[i + 1][j] = 1;

			}
		}
	}

	printf("%d %d\n", ans_r, ans_c);

	return 0;
}*/