/*#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<pair<int, int>> rotate(vector<pair<int, int>> base_offset, int angle) {
	vector <pair<int, int>> new_offset;
	switch (angle) {
	case 0: // 0
		for (int i = 0; i < 4; i++)
			new_offset.push_back(pair<int, int>(base_offset[i].first, base_offset[i].second));
		break;
	case 1: // 90
		for (int i = 0; i < 4; i++)
			new_offset.push_back(pair<int, int>(-1 * base_offset[i].second, base_offset[i].first));
		break;
	case 2: // 180
		for (int i = 0; i < 4; i++)
			new_offset.push_back(pair<int, int>(-1 * base_offset[i].first, -1 * base_offset[i].second));
		break;
	case 3: // 270
		for (int i = 0; i < 4; i++)
			new_offset.push_back(pair<int, int>(base_offset[i].second, -1 * base_offset[i].first));
		break;
	}

	return new_offset;
}

vector<vector<pair<int, int>>> make_all_possible_offset(vector<pair<int, int>> base_offset) {
	vector<vector<pair<int, int>>> offsets;

	// 회전
	for (int a = 0; a < 4; a++)
		offsets.push_back(rotate(base_offset, a));

	// 대칭 후 회전
	for (int k = 0; k < 4; k++)
		base_offset[k] = pair<int, int>(base_offset[k].first, -1 * base_offset[k].second);

	for (int a = 0; a < 4; a++)  // 0, 90,180, 270
		offsets.push_back(rotate(base_offset, a));

	return offsets;
}

int max_score(vector<vector<int>>& arr, vector<vector<pair<int, int>>>& all_offset) {
	int score = 0;
	int num_of_tetro = all_offset.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int t = 0; t < num_of_tetro; t++) {
				int temp_score = 0;
				for (auto& pos : all_offset[t]) {
					int cur_i = i + pos.first, cur_j = j + pos.second;
					if (cur_i < 0 || cur_i >= N || cur_j < 0 || cur_j >= M) {
						temp_score = 0;
						break;
					}
					else temp_score += arr[cur_i][cur_j];
				}
				score = score > temp_score ? score : temp_score;
			}
		}
	}
	return score;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> arr(N);
	for (auto& p : arr) p = vector<int>(M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	vector<vector<pair<int, int>>> tetro(5);
	// 0. ㅁ
	tetro[0] = vector <pair<int, int>>();
	tetro[0].push_back(pair<int, int>(0, 0));
	tetro[0].push_back(pair<int, int>(0, 1));
	tetro[0].push_back(pair<int, int>(1, 0));
	tetro[0].push_back(pair<int, int>(1, 1));

	// 1. ㅡ
	tetro[1] = vector <pair<int, int>>();
	tetro[1].push_back(pair<int, int>(0, 0));
	tetro[1].push_back(pair<int, int>(1, 0));
	tetro[1].push_back(pair<int, int>(2, 0));
	tetro[1].push_back(pair<int, int>(3, 0));

	// 2. ㄱ
	tetro[2] = vector <pair<int, int>>();
	tetro[2].push_back(pair<int, int>(0, 0));
	tetro[2].push_back(pair<int, int>(0, 1));
	tetro[2].push_back(pair<int, int>(0, 2));
	tetro[2].push_back(pair<int, int>(1, 2));

	// 3. ㅏ
	tetro[3] = vector <pair<int, int>>();
	tetro[3].push_back(pair<int, int>(0, 0));
	tetro[3].push_back(pair<int, int>(1, 0));
	tetro[3].push_back(pair<int, int>(2, 0));
	tetro[3].push_back(pair<int, int>(1, 1));

	// 4. 번개
	tetro[4] = vector <pair<int, int>>();
	tetro[4].push_back(pair<int, int>(0, 0));
	tetro[4].push_back(pair<int, int>(1, 0));
	tetro[4].push_back(pair<int, int>(1, 1));
	tetro[4].push_back(pair<int, int>(2, 1));

	vector<vector<pair<int, int>>> all_offset;	// 대칭 * 회전 모든 offset의 경우의 수.

	for (int t = 0; t < tetro.size(); t++) { // 모든 도형에 대해
		vector<vector<pair<int, int>>> temp = make_all_possible_offset(tetro[t]);

		for (auto& p : temp)
			all_offset.push_back(p);
	}
	cout << max_score(arr, all_offset) << "\n";

	return 0;
}*/