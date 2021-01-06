/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int N, M, K; // 밭 세로/가로, 지속 년도
int offset[8][2] = {
	-1, -1,
	-1, 0,
	-1, 1,
	0, -1,
	0, 1,
	1, -1,
	1, 0,
	1, 1
};

inline int check_range(int& i, int& j) {
	if (i<1 || i>N || j<1 || j>N) return 0;
	else return 1;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	vector<vector<int>> nutrition(N + 1, vector<int>(N + 1, 5));		// 영양소 배열
	vector<vector<int>> added_nutrition(N + 1, vector<int>(N + 1, 0));	// 기계가 주는 영양소 
	vector<vector<vector<int>>> trees(N + 1, vector<vector<int>>(N + 1, vector<int>())); // 각 칸의 나무 배열 

	// 더해지는 양분
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> added_nutrition[i][j];

	// 나무 추가
	for (int j = 1; j <= M; j++) {
		int r, c, a;
		cin >> r >> c >> a;
		trees[r][c].push_back(a);
	}


	// 시간 흐름
	while (K--) {
		// 봄 & 여름
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 나무가 없는 경우 패스				
				if (trees[i][j].size() == 0) continue;

				// 나이 순 정렬 
				stable_sort(trees[i][j].begin(), trees[i][j].end());

				// 양분 먹이기 
				int num_of_live_tree = 0;	// 산 나무 수 
				for (auto iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++) {
					int& cur_tree_age = *iter;
					if (nutrition[i][j] >= cur_tree_age) { // 양분을 먹을 수 있는 경우 
						nutrition[i][j] -= cur_tree_age; // 양분 흡수
						cur_tree_age++;					 // 나이 증가
						num_of_live_tree++;				 // 산 나무 수 증가  	
					}
					else { // 양분을 먹을 수 없는 경우 
						for (auto dead_iter = iter; dead_iter != trees[i][j].end(); dead_iter++) {
							nutrition[i][j] += ((*dead_iter) / 2); // 죽은 나무 -> 양분
						}
						trees[i][j].resize(num_of_live_tree); // 죽은 나무 삭제
						break;
					}
				}
			}
		}
		// 가을
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto& t : trees[i][j]) {
					if (t % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int n_i = i + offset[k][0],
								n_j = j + offset[k][1];
							if (check_range(n_i, n_j)) {
								trees[n_i][n_j].push_back(1); // 나무 추가 
							}
						}
					}
				}
			}
		}


		// 겨울 
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				nutrition[i][j] += added_nutrition[i][j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			answer += trees[i][j].size();

	cout << answer << "\n";


	return 0;
}*/