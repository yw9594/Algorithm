//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//	int N;
//	string cmd;
//	queue<int> q;
//	std::ios::sync_with_stdio(false);
//	//cin.tie(0);
//
//	cin >> N;
//
//	while (N--) {
//		cin >> cmd;
//
//		if (cmd == "push") {
//			int x; cin >> x;
//			q.push(x);
//		}
//		else if (cmd == "pop") {
//			int x = -1;
//			if (!q.empty()) {
//				x = q.front();
//				q.pop();
//			}
//			printf("%d\n", x);
//		}
//		else if (cmd == "size") {
//			printf("%d\n", q.size());
//		}
//		else if (cmd == "empty") {
//			printf("%d\n", q.empty());
//		}
//		else if (cmd =="front") {
//			int x = -1;
//			if (!q.empty()) x = q.front();
//			printf("%d\n", x);
//		}
//		else if (cmd=="back") {
//			int x = -1;
//			if (!q.empty()) x = q.back();
//			printf("%d\n", x);
//		}
//	}
//	
//	return 0;
//}