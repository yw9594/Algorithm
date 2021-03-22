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

int N;

// 순서, 중복을 허락하여 경우의 수를 구한다.
int solution(int sum) {
	if (sum > N) return 0;
	if (sum == N) return 1;

	int cnt = 0;
	for (int i = 1; i <= 3; i++)
		cnt += solution(sum + i);
	return cnt;
}

int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		cout << solution(0) << "\n";
	}

	return 0;
}*/