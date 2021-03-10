/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// °øÅë Header ///////////////////////////////////////////////////
#define MAX 99999999
int N, ans = MAX;
vector<int> D;

int solution(int x) {
	if (x == 1) {
		return 0;
	}

	if (D[x] != MAX)
		return D[x];

	vector<int> tmp;

	if (x % 3 == 0) {
		int d3 = solution(x / 3);
		tmp.push_back(d3);
	}
	if (x % 2 == 0) {
		int d2 = solution(x / 2);
		tmp.push_back(d2);
	}
	int d1 = solution(x - 1);
	tmp.push_back(d1);

	auto p = minmax_element(tmp.begin(), tmp.end());
	int m = *(p.first);


	return D[x] = m + 1;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	D = vector<int>(N + 1, MAX);
	D[1] = 0;

	cout << solution(N);


	return 0;
}*/