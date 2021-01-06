/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int N, M, K; // �� ����/����, ���� �⵵
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
	vector<vector<int>> nutrition(N + 1, vector<int>(N + 1, 5));		// ����� �迭
	vector<vector<int>> added_nutrition(N + 1, vector<int>(N + 1, 0));	// ��谡 �ִ� ����� 
	vector<vector<vector<int>>> trees(N + 1, vector<vector<int>>(N + 1, vector<int>())); // �� ĭ�� ���� �迭 

	// �������� ���
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> added_nutrition[i][j];

	// ���� �߰�
	for (int j = 1; j <= M; j++) {
		int r, c, a;
		cin >> r >> c >> a;
		trees[r][c].push_back(a);
	}


	// �ð� �帧
	while (K--) {
		// �� & ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// ������ ���� ��� �н�				
				if (trees[i][j].size() == 0) continue;

				// ���� �� ���� 
				stable_sort(trees[i][j].begin(), trees[i][j].end());

				// ��� ���̱� 
				int num_of_live_tree = 0;	// �� ���� �� 
				for (auto iter = trees[i][j].begin(); iter != trees[i][j].end(); iter++) {
					int& cur_tree_age = *iter;
					if (nutrition[i][j] >= cur_tree_age) { // ����� ���� �� �ִ� ��� 
						nutrition[i][j] -= cur_tree_age; // ��� ���
						cur_tree_age++;					 // ���� ����
						num_of_live_tree++;				 // �� ���� �� ����  	
					}
					else { // ����� ���� �� ���� ��� 
						for (auto dead_iter = iter; dead_iter != trees[i][j].end(); dead_iter++) {
							nutrition[i][j] += ((*dead_iter) / 2); // ���� ���� -> ���
						}
						trees[i][j].resize(num_of_live_tree); // ���� ���� ����
						break;
					}
				}
			}
		}
		// ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto& t : trees[i][j]) {
					if (t % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int n_i = i + offset[k][0],
								n_j = j + offset[k][1];
							if (check_range(n_i, n_j)) {
								trees[n_i][n_j].push_back(1); // ���� �߰� 
							}
						}
					}
				}
			}
		}


		// �ܿ� 
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