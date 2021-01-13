/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// 공통 Header ///////////////////////////////////////////////////

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int N;
		cin >> N;

		// 작년 등수 입력 받기
		vector<int> rank(N + 1); // rank[i] : 작년 i등 팀의 번호
		for (int i = 1; i <= N; i++) {
			cin >> rank[i];
		}

		// 작년 순위 기반 유향 그래프 그리기
		vector<int> in_edge(N + 1, 0);								// 진입 차수
		vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));	// 인접 배열, 유향 그래프 방향 변경용

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				in_edge[rank[j]]++;
				board[rank[i]][rank[j]] = 1;
			}
		}

		// 유향 그래프 방향 전환하기
		int M;
		cin >> M;

		while (M--) {
			int a, b; // a와 b 팀의 위상이 바뀜
			cin >> a >> b;

			if (board[a][b]) { // a가 더 순위가 높았을 경우 : a->b => b->a
				in_edge[a]++;
				in_edge[b]--;
			}
			else { // b가 순위가 더 높았을 경우 : b->a => a->b
				in_edge[a]--;
				in_edge[b]++;
			}

			swap(board[a][b], board[b][a]); // 그래프 방향 역전
		}

		// 위상 정렬
		vector<int> answer; // 1~N등의 팀 번호 저장
		queue<int> q;

		for (int i = 1; i <= N; i++)
			if (in_edge[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int c_t = q.front();
			q.pop();

			answer.push_back(c_t);

			for (int n_t = 1; n_t <= N; n_t++) {
				if (board[c_t][n_t]) { // 다음 순위 팀의 그래프를 조정한다.
					in_edge[n_t]--;      // in_edge 제거 

					if (in_edge[n_t] == 0)
						q.push(n_t);
				}
			}
		}

		// 정답 출력
		if (answer.size() != N) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			for (auto& e : answer)
				cout << e << " ";
			cout << "\n";
		}

	}

	return 0;
}*/