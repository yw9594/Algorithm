/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

#define MAX 1000000

using LL = long long int;

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	// d[i] : �� i�� ����� ��
	// i = a * b �̹Ƿ�, bottom-up ������� ����� ���س�����.
	// O(NlogN)�� �ð����⵵�� ������. 
	vector<LL> d(MAX + 1, 1);
	for (LL a = 2; a <= MAX; a++) {
		for (LL b = 1; a * b <= MAX; b++) {
			d[a * b] += a;
		}
	}
	/// s[i] : i��° �������� ��� ���� ��
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