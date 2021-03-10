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

lld d[10]; // 10^d-1 자릿수의 개수
lld p[10]; // 10의 제곱수

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	// 자릿수 별 개수 초기화
	d[0] = 9;	// 9 : 1의 자리 수의 개수 1~9
	p[0] = 1;	// 1 : 10^0 
	for (int i = 1; i <= 9; i++) {
		d[i] = d[i - 1] * 10;			// 9, 90, 900, ....
		p[i] = p[i - 1] * 10;			// 1, 10, 100, ....
	}
	// 자릿수 별 길이 합 구하기
	int n_d = to_string(N).length() - 1;	// 입력 수의 10의 제곱 수

	lld sum = 0LL;

	for (int i = 0; i < n_d; i++) {
		sum += (d[i] * (i + 1));
	}

	sum += (N - p[n_d] + 1) * (n_d + 1);
	cout << sum << "\n";

	return 0;
}*/