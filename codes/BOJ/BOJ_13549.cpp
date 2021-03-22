/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

#define INF 987654321

struct Elem {
	int i, c; // 위치, 시간
	bool operator<(const Elem& arg) const {
		return this->c > arg.c; // minimum heap
	}
};

int check_range(int i) {
	if (i < 0 || i> 100000) return 0;
	else return 1;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, answer = INF;
	cin >> N >> K;

	priority_queue<Elem> pq;
	vector<int> dist(100001, INF);

	pq.push({ N, 0 });
	dist[N] = 0;

	while (!pq.empty()) {
		Elem c_e = pq.top();
		pq.pop();


		if (c_e.c > dist[c_e.i]) continue; // 더 작은 경로가 존재할 경우 pass

		// 다음 노드 입력
		int n_i[] = { c_e.i * 2 , c_e.i + 1, c_e.i - 1 };
		int n_c[] = { c_e.c, c_e.c + 1, c_e.c + 1 };

		for (int k = 0; k < 3; k++) {
			if (check_range(n_i[k]) && n_c[k] < dist[n_i[k]]) {
				pq.push({ n_i[k], n_c[k] });
				dist[n_i[k]] = n_c[k];
			}
		}
	}

	cout << answer << "\n";

	return 0;
}*/