//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int MX = 51;
//
//int pre[MX], dat[MX], nex[MX];
//int arr[MX];
//
//int main(void) {
//	int N, K, ans = 0;
//	int cursor = 1, cnt, idx=1;
//	std::ios::sync_with_stdio(false);
//	
//	freopen("input.txt", "r", stdin);
//
//	cin >> N >> K;
//	for (int i = 1; i <= K; i++) cin >> arr[i];
//
//	// 1. init values.
//	for (int i = 1; i <= N; i++) dat[i] = i;	
//	for (int i = 1; i < N; i++) {
//		pre[i + 1] = i;
//		nex[i] = i + 1;
//	}
//	pre[1] = N;
//	nex[N] = 1;
//
//	// 2. algorithme start
//	while (idx <= K) {
//		// 1. get next cursor position.
//		cnt = 0;
//
//		while (dat[cursor] != arr[idx]) { // rotate clock-wise until matching next pop element			
//			cursor = nex[cursor];
//			cnt++;
//		}	
//
//		cnt = (N - cnt) < cnt ? (N - cnt) : cnt; // if counter clock-wise is less than cnt, change value.
//		ans += cnt;
//
//		// 2. erase.
//		int left = pre[cursor], right = nex[cursor];
//		if (N==1 ) { // only 1 element left. notthing to do.
//			pre[cursor] = nex[cursor] = -1;
//		}
//		else if (N==2) { // 2 elements left. need to right(left element node's right and left refer to itself.
//			pre[cursor] = nex[cursor] = -1;
//			pre[right] = nex[right] = right;
//			cursor = right;
//		}
//		else{ // 3 or more elements over left. link left and right node of current node.
//			pre[cursor] = nex[cursor] = -1;
//			nex[left] = right;
//			pre[right] = left;
//			cursor = right;
//		}
//
//		N--;	// array length reduced.
//		idx++;
//	}
//
//
//	cout << ans << "\n";
//
//	return 0;
//}