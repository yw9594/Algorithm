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

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		// M, N�� �������� ���߱� ���� 1 ����
		x--;
		y--;

		// A����� +M���� ���ذ��� y�� ��ġ�ϴ� A�� �˻�
		int ans = -1;
		int g = gcd(M, N);
		int l = M * N / g; // M�� N�� �ּҰ�����⵵���� x, y���� ��������. �� ��, A�� M�����Ƿ� �ð����⵵��  O((�ּҰ����/M)==O(N)�̴�.


		for (int A = x; A <= l; A += M) {
			int c_y = A % N;
			if (c_y == y) {
				ans = A + 1; // A�� 0�⵵���� �ϹǷ� �ٽ� 1 �ø���. 
			}
		}

		cout << ans << "\n";
	}


	return 0;
}*/