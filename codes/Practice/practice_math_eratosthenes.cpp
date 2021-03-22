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
using LL = long long int;

void prime_filter(vector<LL>& f) {

	for (int i = 2; i <= MAX; i++) {
		if (f[i] != 0) {
			for (int j = 2; i * j <= MAX; j++)
				f[i * j] = 0;
		}
	}

	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	vector<LL> f(MAX + 1, 0);
	for (int i = 2; i <= MAX; i++) f[i] = i;

	// 에라토스테네스의 채
	prime_filter(f);

	for (int i = a; i <= b; i++)
		if (f[i] != 0)
			cout << f[i] << "\n";

	return 0;
}*/