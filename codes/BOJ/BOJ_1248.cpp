/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// °øÅë Header ///////////////////////////////////////////////////
int N;
vector<vector<char>> arr;

vector<int> ans(0);

bool check(int idx, vector<vector<int>>& s) {

	for (int i = 0; i <= idx; i++) {
		for (int j = i; j <= idx; j++) {
			if ((s[i][j] > 0 && arr[i][j] != '+') ||
				(s[i][j] == 0 && arr[i][j] != '0') ||
				(s[i][j] < 0 && arr[i][j] != '-')
				)
				return false;
		}
	}

	return true;
}

void add(int idx, int n, int sign, vector<vector<int>>& s) {
	for (int i = 0; i <= idx; i++) {
		if (i != idx)
			s[i][idx] = s[i][idx - 1] + (n * sign);
		else
			s[i][idx] += (n * sign);

	}
}

void solution(int idx, vector<int>& tmp_ans, vector<vector<int>>& s) {

	if (idx == N) {
		ans = tmp_ans;
		return;
	}

	for (int i = -10; i <= 10 && ans.size() == 0; i++) {
		tmp_ans.push_back(i);
		add(idx, i, 1, s);

		if (check(idx, s)) {
			solution(idx + 1, tmp_ans, s);
		}

		tmp_ans.pop_back();
		add(idx, i, -1, s);
	}
	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N;
	arr = vector<vector<char>>(N, vector<char>(N, 0));


	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> tmp_ans;
	vector<vector<int>> s(N, vector<int>(N, 0));
	solution(0, tmp_ans, s);

	for (auto& e : ans)
		cout << e << " ";
	cout << "\n";

	return 0;
}*/