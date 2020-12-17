//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//const int MX = 100001;
//
//int main(void) {
//	int N, i=1, k=1;
//	int arr[MX], num[MX];
//	stack<int> stk;
//	vector<char> vec;
//
//	std::ios::sync_with_stdio(false);
//	cin >> N;
//
//	for (int i = 1; i <= N; i++) cin >> arr[i];
//	for (int i = 1; i <= N; i++) num[i] = i;
//
//	while (k<=N) {
//		if (!stk.empty() && stk.top()==arr[k]) {
//			vec.push_back('-');
//			stk.pop();
//			k++;
//		}
//		else {
//			if (i > N) break;
//
//			vec.push_back('+');
//			stk.push(num[i++]);
//		}
//	}
//
//	if (!stk.empty()) cout << "No\n";
//	else
//		for (auto& c : vec) cout << c << "\n";
//	return 0;
//}