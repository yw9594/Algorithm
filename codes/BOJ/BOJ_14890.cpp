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
int N, L, answer = 0;

int check_range(int& i, int& j) {
	if (i < 0 || i >= N || j < 0 || j >= N) return 0;
	return 1;
}

void check_route(vector<vector<int>>& board) {
	// 가로 길 개수 구하기
	for (int r = 0; r < N; r++) {
		int flag = true;	       // 길 존재 여부
		vector<int> checked(N, 0); // 경사로 설치 여부

		for (int c = 0; c < N - 1; c++) {
			// 다음 칸 높이가 같은 경우
			if (board[r][c] == board[r][c + 1]) continue;

			// 다음 칸 높이가 다른 경우
			else {
				// 1 이상 차이날 경우 불가능
				if (abs(board[r][c] - board[r][c + 1]) > 1) {
					flag = false;
					break;
				}
				// 1만큼 차이 나는 경우
				else {
					int low, high;

					// 현재 칸이 더 낮은 경우
					if (board[r][c] < board[r][c + 1])
						low = c - L + 1, high = c;

					// 현재 칸이 더 높은 경우
					else
						low = c + 1, high = c + L;

					// 범위를 벗어나는 경우 경사로 불가
					if (!check_range(low, high)) {
						flag = false;
						break;
					}
					// 경사로를 놓을 수 있는 경우 
					else {
						// 경사로 놓을 길 체크 
						int height = board[r][low];
						if (checked[low]) {
							flag = false;
							break;
						}
						for (int k = low + 1; k <= high && flag; k++)
							if (checked[k] || board[r][k] != height) // 이미 경사로가 설치되어있거나 높이가 다른 경우
								flag = false;


						// 경사로 설치
						if (flag)
							for (int k = low; k <= high; k++) checked[k] = 1;

						// 경사로 설치 불가능 
						else break;

					}
				}
			}
		}
		// 길이 있는 경우 추가
		if (flag) answer++;
	}

	// 세로 길 개수 구하기
	for (int c = 0; c < N; c++) {
		int flag = true;	       // 길 존재 여부
		vector<int> checked(N, 0); // 경사로 설치 여부

		for (int r = 0; r < N - 1; r++) {
			// 다음 칸 높이가 같은 경우
			if (board[r][c] == board[r + 1][c]) continue;

			// 다음 칸 높이가 다른 경우
			else {
				// 1 이상 차이날 경우 불가능
				if (abs(board[r][c] - board[r + 1][c]) > 1) {
					flag = false;
					break;
				}
				// 1만큼 차이 나는 경우
				else {
					int low, high;

					// 현재 칸이 더 낮은 경우
					if (board[r][c] < board[r + 1][c])
						low = r - L + 1, high = r;

					// 현재 칸이 더 높은 경우
					else
						low = r + 1, high = r + L;

					// 범위를 벗어나는 경우 경사로 불가
					if (!check_range(low, high)) {
						flag = false;
						break;
					}
					// 경사로를 놓을 수 있는 경우 
					else {
						// 경사로 놓을 길 체크 
						int height = board[low][c];
						if (checked[low]) {
							flag = false;
							break;
						}
						for (int k = low + 1; k <= high && flag; k++) {
							if (checked[k] || board[k][c] != height) {// 이미 경사로가 설치되어있거나 높이가 다른 경우
								flag = false;
							}
						}


						// 경사로 설치
						if (flag)
							for (int k = low; k <= high; k++) checked[k] = 1;

						// 경사로 설치 불가능 
						else {
							break;
						}

					}
				}
			}
		}
		// 길이 있는 경우 추가
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