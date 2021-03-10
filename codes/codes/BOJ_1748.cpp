/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

using lld = long long int;

lld d[10]; // 10^d-1 �ڸ����� ����
lld p[10]; // 10�� ������

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	// �ڸ��� �� ���� �ʱ�ȭ
	d[0] = 9;	// 9 : 1�� �ڸ� ���� ���� 1~9
	p[0] = 1;	// 1 : 10^0 
	for (int i = 1; i <= 9; i++) {
		d[i] = d[i - 1] * 10;			// 9, 90, 900, ....
		p[i] = p[i - 1] * 10;			// 1, 10, 100, ....
	}
	// �ڸ��� �� ���� �� ���ϱ�
	int n_d = to_string(N).length() - 1;	// �Է� ���� 10�� ���� ��

	lld sum = 0LL;

	for (int i = 0; i < n_d; i++) {
		sum += (d[i] * (i + 1));
	}

	sum += (N - p[n_d] + 1) * (n_d + 1);
	cout << sum << "\n";

	return 0;
}*/