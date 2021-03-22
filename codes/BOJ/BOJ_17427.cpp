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
	long long int sum = 0LL;

	cin >> N;

	for (int i = 1; i <= N; i++)
		sum += (N / i) * i;

	cout << sum << "\n";
	return 0;
}*/