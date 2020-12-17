/*
	Point.
		if the team is not made, that means, there are students who didn't get invitation.		
		i.e Their income edge count is 0.

	How to solve?
		1. push all nodes that have zero income edge.
		2. while poping element from queue, delete node, add 1 to ans.
		3. if zero income node is maded while poping, push that node.
*/
//
//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//const int MX = 100001;
//
//int main(void) {
//	int T;
//	std::ios::sync_with_stdio(false);
//
//	freopen("input.txt", "r", stdin);
//
//	cin >> T;
//	while (T--) {
//		int N, T = 0, ans = 0;
//		int arr[MX], income[MX] = {0};
//		queue<int> q;
//
//		cin >> N;
//		for (int i = 1; i <= N; i++) {
//			cin >> arr[i];
//			income[arr[i]]++;	// count income edges.
//		}
//		
//		for (int i = 1; i <= N; i++) if (income[i] == 0) q.push(i);
//
//		while (!q.empty()) {
//			int cur_node = q.front();
//			q.pop();
//			ans++;
//			if (--income[arr[cur_node]] == 0) q.push(arr[cur_node]);
//		}
//		cout << ans << "\n";
//	}
//
//	return 0;
//}