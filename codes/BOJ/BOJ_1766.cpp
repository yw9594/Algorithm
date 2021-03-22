/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++) arr[i] = i; // ���� ����

	// ���� ���� ����
	vector<int> in_edge(N + 1, 0);
	vector<vector<int>> out_edge(N + 1, vector<int>());

	while (M--) {
		int a, b;
		cin >> a >> b;
		in_edge[b]++;
		out_edge[a].push_back(b);
	}

	// ���� ����
	priority_queue<int, vector<int>, greater<int>> q; // �����ϴٸ� ���� ��ȣ�� ���� �������� Ǫ�� ���� �����Ƿ� Heap�� ����Ѵ�.
	for (int i = 1; i <= N; i++) {
		if (in_edge[i] == 0) q.push(i);
	}

	vector<int> topology;
	vector<int> checked(N + 1, 0);
	while (!q.empty()) {
		int cur_node = q.top();
		q.pop();

		topology.push_back(cur_node);
		checked[cur_node] = 1;

		for (auto& a : out_edge[cur_node]) {
			in_edge[a]--; // ���� ����
			if (in_edge[a] == 0)
				q.push(a);
		}
	}


	for (auto& e : topology)
		cout << e << " ";
	cout << "\n";


	return 0;
}*/