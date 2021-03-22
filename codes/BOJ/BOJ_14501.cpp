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

int N, ans = 0;
vector<int> t;
vector<int> p;

int solution(int i) {
	if (i > N) return 0;

	int a = 0, b = 0;

	// 현재 날짜에 상담을 하는 경우
	if (i + t[i] - 1 <= N) // 상담을 마치는 날짜가 N을 넘어서는 경우, 상담이 불가능하다.
		a = p[i] + solution(i + t[i]);

	// 현재 날짜에 상담을 안하는 경우
	b = solution(i + 1);

	return a > b ? a : b;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력 받기
	cin >> N;
	t = vector<int>(N + 1, 0);
	p = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> t[i] >> p[i];

	cout << solution(1) << "\n";



	return 0;
}*/