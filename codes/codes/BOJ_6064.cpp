/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

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

		// M, N의 나머지에 맞추기 위해 1 감소
		x--;
		y--;

		// A년부터 +M년을 더해가며 y가 일치하는 A년 검사
		int ans = -1;
		int g = gcd(M, N);
		int l = M * N / g; // M과 N의 최소공배수년도부터 x, y값이 같아진다. 이 때, A가 M씩들어나므로 시간복잡도는  O((최소공배수/M)==O(N)이다.


		for (int A = x; A <= l; A += M) {
			int c_y = A % N;
			if (c_y == y) {
				ans = A + 1; // A는 0년도부터 하므로 다시 1 올린다. 
			}
		}

		cout << ans << "\n";
	}


	return 0;
}*/