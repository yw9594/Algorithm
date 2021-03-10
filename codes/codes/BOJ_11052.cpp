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



int main(void) {
	freopen("input.txt", "r", stdin);

	int N;
	vector<int> P;

	cin >> N;
	P = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> P[i];

	vector<int> D(N + 1, 0);

	for (int i = 1; i <= N; i++) {			// D[i] : i개 구매했을 때 총 비용 최대값
		for (int j = i; j >= 1; j--) {		// D[i] = max(P[j] + D[i-j])
			int c_p = P[j] + D[i - j];
			D[i] = D[i] > c_p ? D[i] : c_p;
		}
	}

	cout << D[N];

	return 0;
}*/