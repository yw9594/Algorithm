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
int broken[10] = { 0 };


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

	// 채널 C가 유효한 번호인지 검사하고, 횟수를 구한다. 
	int ans = 1000000;
	for (int c = 0; c <= 1000000; c++) {
		string ch = to_string(c);
		int len = ch.size();


		// 고장난 버튼이 있는 경우, 넘어간다.
		int flag = false;
		for (int i = 0; i < len; i++)
			if (broken[ch[i] - '0'])
				flag = true;
		if (flag) continue;

		// 채널 c 에서 채널 N으로 이동하기 위한 최소값을 구한다.

		int click = len + abs(N - c);
		ans = ans < click ? ans : click;

	}

	cout << (ans < abs(N - 100) ? ans : abs(N - 100)) << "\n";

	return 0;
}*/