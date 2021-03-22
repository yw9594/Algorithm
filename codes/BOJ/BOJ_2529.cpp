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

using lld = long long int;

int N; // N개 부등호, N+1개의 숫자
vector<char> arr;
vector<int> checked(10, 0);

vector<string> ans;

bool ok(string& num) {
	for (int i = 0; i < N; i++) {
		if ((arr[i] == '<' && num[i] > num[i + 1]) ||
			(arr[i] == '>' && num[i] < num[i + 1]))
			return false;
	}
	return true;

}
bool prun(char a, char b, char c) {
	if (c == '<') return a < b;
	else return a > b;

}

void solution(int idx, string num) {
	if (idx == N + 1) {
		if (ok(num))
			ans.push_back(num);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (checked[i]) continue;

		if (idx == 0 || prun(num[idx - 1], i + '0', arr[idx - 1])) {
			checked[i] = 1;

			solution(idx + 1, num + to_string(i));

			checked[i] = 0;
		}
	}
	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	// 입력 받기
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr = vector<char>(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	solution(0, "");

	auto p = minmax_element(ans.begin(), ans.end());

	cout << *p.second << "\n";
	cout << *p.first << "\n";

	return 0;
}*/