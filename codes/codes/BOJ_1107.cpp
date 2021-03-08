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
	// 7�ڸ� �̻� �Ѿ�� �ʴ´�. 
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

	// �Է� �ޱ�
	cin >> N >> M;
	while (M--) {
		int b_n;
		cin >> b_n;
		broken[b_n] = 1;
	}

	// ������ ��� �� ��, N�� ���� ����� �� K ���ϱ�
	getK();



	// ���� ���ϱ�
	ans = ans < abs(N - 100) ? ans : abs(N - 100);
	cout << ans << "\n";

	return 0;
}*/