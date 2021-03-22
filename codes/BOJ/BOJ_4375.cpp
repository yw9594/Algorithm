/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// °øÅë Header ///////////////////////////////////////////////////

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	while (cin >> N) {

		int long long K = 1LL;
		int cnt = 1;
		while (1) {
			if (K % N == 0)
				break;

			K = (K * 10LL) % N + 1LL;
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}*/