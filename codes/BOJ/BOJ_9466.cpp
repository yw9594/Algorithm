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
//		int N, T = 0, ans=0;				// num of student, num ob team. 
//		int arr[MX], checked[MX];	// -1: not checked, 0: no team, 1~: team number
//		queue<int> q;				// pre-team member. team is determined after cycle occured.
//
//		fill(checked, checked + MX, -1);
//
//		cin >> N;
//		for (int i = 1; i <= N; i++) cin >> arr[i]; // i: num of student.
//
//		for (int i = 1; i <= N; i++) {	// match team.
//			if (checked[i] == -1) {		// if not checked student is found, match team.
//				int cur_node = i;
//				q.push(i);
//				checked[i] = ++T;
//				while (1) {
//					cur_node = arr[cur_node];	// check next node.
//
//					if (checked[cur_node] == -1) { // if current student is not matched to any team.
//						q.push(cur_node);		
//						checked[cur_node] = T;
//					}
//					else if (checked[cur_node] == T) { // team matching occur. seperate team member.
//						// cout << "cycle founded.\n";
//						while (!q.empty() && q.front() != cur_node) { // all nodes before cur_node cant make team.
//							checked[q.front()] = 0;
//							ans++;
//							q.pop();
//						}
//						while (!q.empty()) { // rest of students are team.
//							q.pop();
//						}
//						break;
//					}
//					else { // previous student want to match with student who wasn't matched team or was belonged to another team.
//						while (!q.empty()) { // all nodes cant make team.
//							checked[q.front()] = 0;
//							ans++;
//							q.pop();
//						}
//						break;
//					}
//				}
//			}
//		}
//		//for (int i = 1; i <= N; i++) cout <<checked[i]<<" "; // i: num of student.
//		//cout<<"\n";
//		cout << ans << "\n";
//	}
//	return 0;
//}