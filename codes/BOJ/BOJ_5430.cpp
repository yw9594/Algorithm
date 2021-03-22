//#include <iostream>
//
//using namespace std;
//
//const int MX = 100001;
//
//void toArr(int arr[], string& arr_s, int len) { // arr_s to arr
//	int arr_s_len = arr_s.size(), idx;
//	if (arr_s_len == 2) // "[]" 
//		return;
//
//	arr_s = arr_s.substr(1, arr_s.size() - 2); // [1,2,3] -> ,1,2,3
//	arr_s = "," + arr_s;
//
//	idx = arr_s.size() - 1;
//
//	int num = 0, exp = 1;
//	while (idx > -1) {
//		if (arr_s[idx] != ',') {
//			num += (arr_s[idx] - '0') * exp;
//			exp *= 10;
//		}
//		else {
//			arr[len--] = num;
//			num = 0;
//			exp = 1;
//		}
//		idx--;
//	}
//}
//
//int main(void) {
//	int N;
//
//	freopen("input.txt", "r", stdin);
//
//	std::ios::sync_with_stdio(false);
//	cin >> N;
//
//	while (N--) {
//		bool flag = true, dir = false; // is ans? / forward, backward
//		int len, front, rear;
//		int arr[MX];
//		string ops, arr_s;
//
//		cin >> ops >> len >> arr_s;
//
//		toArr(arr, arr_s, len - 1);
//
//		if (len != 0) { front = 0, rear = len - 1; }
//		else front = rear = -1; // no elements.
//
//		for (int i = 0; i < ops.size(); i++) {
//			char op = ops[i];
//
//			switch (op) {
//			case 'R':
//				dir = !dir;
//				break;
//
//			case 'D':
//				if (len == 0 || front > rear) { // len==0 or all elements is deleted : error
//					flag = false;
//					break;
//				}
//				if (!dir) // forward
//					front++;
//				else  // backward
//					rear--;
//
//				break;
//			}
//		}
//
//		if (flag) {
//			if (len == 0) cout << "[]\n";
//			else if (!dir) {
//				cout << "[";
//				for (int i = front; i <= rear; i++) {
//					if (i != rear) cout << arr[i] << ",";
//					else cout << arr[i];
//				}
//				cout << "]\n";
//			}
//			else {
//				cout << "[";
//				for (int i = rear; i >= front; i--) {
//					if (i != front) cout << arr[i] << ",";
//					else cout << arr[i];
//				}
//				cout << "]\n";
//			}
//		}
//		else cout << "error\n";
//	}
//	return 0;
//}