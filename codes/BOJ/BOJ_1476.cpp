/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// °øÅë Header ///////////////////////////////////////////////////

int arr[16][29][20] = { 0 };

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int E, S, M;
	cin >> E >> S >> M;

	for (int e = 1, s = 1, m = 1, y = 1; y <= 7980; y++, e++, s++, m++) {

		e = e > 15 ? 1 : e;
		s = s > 28 ? 1 : s;
		m = m > 19 ? 1 : m;

		arr[e][s][m] = arr[e][s][m] == 0 ? y : arr[e][s][m];
	}

	cout << arr[E][S][M] << "\n";


	return 0;
}*/