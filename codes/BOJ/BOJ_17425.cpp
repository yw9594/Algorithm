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

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	// d[i] : 수 i의 약수의 합
	// i = a * b 이므로, bottom-up 방식으로 약수의 구해나간다.
	// O(NlogN)의 시간복잡도를 가진다. 
	vector<LL> d(MAX + 1, 1);
	for (LL a = 2; a <= MAX; a++) {
		for (LL b = 1; a * b <= MAX; b++) {
			d[a * b] += a;
		}
	}
	/// s[i] : i번째 수까지의 약수 합의 합
	vector<LL> s(MAX + 1, 0);
	for (int i = 1; i <= MAX; i++) {
		s[i] = s[i - 1] + d[i];
	}

	while (T--) {
		int N;
		cin >> N;
		cout << s[N] << "\n";
	}

	return 0;
}*/