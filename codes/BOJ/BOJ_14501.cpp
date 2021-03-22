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

int N, ans = 0;
vector<int> t;
vector<int> p;

int solution(int i) {
	if (i > N) return 0;

	int a = 0, b = 0;

	// ���� ��¥�� ����� �ϴ� ���
	if (i + t[i] - 1 <= N) // ����� ��ġ�� ��¥�� N�� �Ѿ�� ���, ����� �Ұ����ϴ�.
		a = p[i] + solution(i + t[i]);

	// ���� ��¥�� ����� ���ϴ� ���
	b = solution(i + 1);

	return a > b ? a : b;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է� �ޱ�
	cin >> N;
	t = vector<int>(N + 1, 0);
	p = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> t[i] >> p[i];

	cout << solution(1) << "\n";



	return 0;
}*/