/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int N, ans = 9999999;
vector<vector<int>> arr;
vector<int> checked;

void solution(int idx, vector<int>& a_team) {
	if (idx >= N) return;

	// �� ���� N/2 ���� ���� ���
	if (a_team.size() == N / 2) {
		int a = 0, b = 0; // a��, b�� �ó��� ��

		// b �� ���ϱ�
		vector<int> b_team;
		for (int i = 0; i < N; i++)
			if (!checked[i])
				b_team.push_back(i);

		// a �� �ó��� ���ϱ� 
		for (auto& i : a_team)
			for (auto& j : a_team)
				a += arr[i][j];

		// b �� �ó��� ���ϱ� 
		for (auto& i : b_team)
			for (auto& j : b_team)
				b += arr[i][j];

		ans = ans < abs(a - b) ? ans : abs(a - b);
		return;
	}

	// idx ������ ������ �ִ� ���
	a_team.push_back(idx);
	checked[idx] = 1;

	solution(idx + 1, a_team);

	a_team.pop_back();
	checked[idx] = 0;

	// idx ������ �ȳִ� ���
	solution(idx + 1, a_team);

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	// �Է�
	cin >> N;
	arr = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// �ذ�
	vector<int> a_team;
	checked = vector<int>(N, 0);
	solution(0, a_team);
	cout << ans << "\n";
	return 0;
}*/