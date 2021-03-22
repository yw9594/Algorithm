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
int N, M, K;
int broken[10] = { 0 };


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է� �ޱ�
	cin >> N >> M;
	while (M--) {
		int b_n;
		cin >> b_n;
		broken[b_n] = 1;
	}

	// ä�� C�� ��ȿ�� ��ȣ���� �˻��ϰ�, Ƚ���� ���Ѵ�. 
	int ans = 1000000;
	for (int c = 0; c <= 1000000; c++) {
		string ch = to_string(c);
		int len = ch.size();


		// ���峭 ��ư�� �ִ� ���, �Ѿ��.
		int flag = false;
		for (int i = 0; i < len; i++)
			if (broken[ch[i] - '0'])
				flag = true;
		if (flag) continue;

		// ä�� c ���� ä�� N���� �̵��ϱ� ���� �ּҰ��� ���Ѵ�.

		int click = len + abs(N - c);
		ans = ans < click ? ans : click;

	}

	cout << (ans < abs(N - 100) ? ans : abs(N - 100)) << "\n";

	return 0;
}*/