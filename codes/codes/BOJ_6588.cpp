/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

#define MAX 1000000
using p_i = pair<int, int>;

void prime_filter(vector<int>& f, vector<int>& ps) {
	for (int i = 2; i <= MAX; i++) {
		if (f[i] != 0) {
			ps.push_back(i);
			for (int j = i + i; j <= MAX; j += i) {
				f[j] = 0;
			}
		}
	}
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	// 에라토스테네트의 채를 통한 10000000 이하의 수 중, 3 이상의 소수 체크
	vector<int> f(MAX + 1, 0);
	vector<int> ps;
	for (int i = 2; i <= MAX; i++) f[i] = i;

	prime_filter(f, ps);

	int len = ps.size();

	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < len; i++) {
			if (f[N - ps[i]] != 0) {
				cout << N << " = " << ps[i] << " + " << N - ps[i] << "\n";
				break;
			}
		}
	}

	return 0;
}*/