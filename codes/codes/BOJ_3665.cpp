/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int N;
		cin >> N;

		// �۳� ��� �Է� �ޱ�
		vector<int> rank(N + 1); // rank[i] : �۳� i�� ���� ��ȣ
		for (int i = 1; i <= N; i++) {
			cin >> rank[i];
		}

		// �۳� ���� ��� ���� �׷��� �׸���
		vector<int> in_edge(N + 1, 0);								// ���� ����
		vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));	// ���� �迭, ���� �׷��� ���� �����

		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				in_edge[rank[j]]++;
				board[rank[i]][rank[j]] = 1;
			}
		}

		// ���� �׷��� ���� ��ȯ�ϱ�
		int M;
		cin >> M;

		while (M--) {
			int a, b; // a�� b ���� ������ �ٲ�
			cin >> a >> b;

			if (board[a][b]) { // a�� �� ������ ������ ��� : a->b => b->a
				in_edge[a]++;
				in_edge[b]--;
			}
			else { // b�� ������ �� ������ ��� : b->a => a->b
				in_edge[a]--;
				in_edge[b]++;
			}

			swap(board[a][b], board[b][a]); // �׷��� ���� ����
		}

		// ���� ����
		vector<int> answer; // 1~N���� �� ��ȣ ����
		queue<int> q;

		for (int i = 1; i <= N; i++)
			if (in_edge[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int c_t = q.front();
			q.pop();

			answer.push_back(c_t);

			for (int n_t = 1; n_t <= N; n_t++) {
				if (board[c_t][n_t]) { // ���� ���� ���� �׷����� �����Ѵ�.
					in_edge[n_t]--;      // in_edge ���� 

					if (in_edge[n_t] == 0)
						q.push(n_t);
				}
			}
		}

		// ���� ���
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