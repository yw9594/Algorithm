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

int N, ans = 9999999;
vector<vector<int>> arr;
vector<int> checked;

void solution(int idx, vector<int>& a_team) {
	if (idx >= N) return;

	// 한 팀에 N/2 명이 모인 경우
	if (a_team.size() == N / 2) {
		int a = 0, b = 0; // a팀, b팀 시너지 합

		// b 팀 구하기
		vector<int> b_team;
		for (int i = 0; i < N; i++)
			if (!checked[i])
				b_team.push_back(i);

		// a 팀 시너지 구하기 
		for (auto& i : a_team)
			for (auto& j : a_team)
				a += arr[i][j];

		// b 팀 시너지 구하기 
		for (auto& i : b_team)
			for (auto& j : b_team)
				b += arr[i][j];

		ans = ans < abs(a - b) ? ans : abs(a - b);
		return;
	}

	// idx 선수를 팀으로 넣는 경우
	a_team.push_back(idx);
	checked[idx] = 1;

	solution(idx + 1, a_team);

	a_team.pop_back();
	checked[idx] = 0;

	// idx 선수를 안넣는 경우
	solution(idx + 1, a_team);

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	// 입력
	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// 해결
	vector<int> a_team;
	checked = vector<int>(N, 0);
	solution(0, a_team);
	cout << ans << "\n";
	return 0;
}*/