/*#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX_DIST 99999999999999LL

using namespace std;

long long int get_chicken_dist(pair<int, int>& a, pair<int, int>& b) {
	return (long long int)(abs(a.first - b.first)) + (long long int)abs(a.second - b.second);
}

void get_k_chicken(vector<vector<int>>& selected, vector<int>& cur_case, int cur_idx, int M, int limit) {
	if (cur_case.size() == M || cur_idx == limit) { // k개를 모두 선택한 경우 또는 최대 치킨 집까지 도달한 경우
		selected.push_back(vector<int>(cur_case));
		return;
	}

	// 현재 원소를 포함 한 경우
	cur_case.push_back(cur_idx);
	get_k_chicken(selected, cur_case, cur_idx + 1, M, limit);
	cur_case.pop_back();

	// 현재 치킨집을 포함 안한 경우
	get_k_chicken(selected, cur_case, cur_idx + 1, M, limit);
	return;
}


vector<vector<int>> get_m_chicken(vector<pair<int, int>>& chicken, int M) {
	vector<vector<int>> selected; // 최대 M개 치킨집을 선택하는 모든 인덱스
	vector<int> cur_case;
	int chicken_num = chicken.size();

	get_k_chicken(selected, cur_case, 0, M, chicken_num);

	return selected;
}

int main(void) {
	int N, M;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<pair<int, int>> house;   // 첫 원소는 더미 데이터
	vector<pair<int, int>> chicken; // 첫 원소는 더미 데이터

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cell;
			cin >> cell;

			if (cell == 1)
				house.push_back(pair<int, int>(i, j));
			else if (cell == 2)
				chicken.push_back(pair<int, int>(i, j));
		}
	}

	vector<vector<int>> all_cases = get_m_chicken(chicken, M);
	long long int answer = MAX_DIST;
	for (auto& c : all_cases) {
		long long int temp_answer = 0LL;
		for (auto& h : house) {
			long long int h_chicken_dist = MAX_DIST;
			for (auto& p : c) {
				long long int temp_h_chicken_dist = get_chicken_dist(chicken[p], h);
				h_chicken_dist = h_chicken_dist < temp_h_chicken_dist ? h_chicken_dist : temp_h_chicken_dist;

			}
			temp_answer += h_chicken_dist;
		}
		answer = answer < temp_answer ? answer : temp_answer;

	}
	cout << answer << "\n";

	return 0;
}*/