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
void solution(int sum, int& cnt) {
	if (sum >= N || cnt == N) {
		if (sum == N) cnt++;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			solution(sum + i, cnt);
		}
	}
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;

		int cnt = 0;
		solution(0, cnt);

		cout << cnt << "\n";
	}

	return 0;
}*/