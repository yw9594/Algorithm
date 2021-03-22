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
int N, M, K;
int ans = 1000000;
int broken[10] = { 0 };
int times[6] = { 1, 10, 100, 1000, 10000, 100000 };

int getD(int n) {
	if (n == 0) return 1;
	else {
		int cnt = 0;
		while (n != 0) {
			n /= 10;
			cnt++;
		}
		return cnt;
	}
}

void getK(int c_K = 0, int digit = 0) {
	// 7자리 이상 넘어가지 않는다. 
	if (digit == 6) return;
	else {
		for (int i = 0; i < 10; i++) {
			if (!broken[i]) {
				c_K += i * times[digit];

				int tmp_ans = getD(c_K) + abs(N - c_K);
				if (tmp_ans < ans) {
					ans = tmp_ans;
				}
				getK(c_K, digit + 1);

				c_K -= i * times[digit];
			}
		}
	}
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// 입력 받기
	cin >> N >> M;
	while (M--) {
		int b_n;
		cin >> b_n;
		broken[b_n] = 1;
	}

	// 가능한 모든 수 중, N과 가장 가까운 수 K 구하기
	getK();



	// 정답 구하기
	ans = ans < abs(N - 100) ? ans : abs(N - 100);
	cout << ans << "\n";

	return 0;
}*/