//#include <iostream>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//const int MX = 1000001;
//
//int main(void) {
//	int N;
//	std::ios::sync_with_stdio(false);
//	
//	freopen("input.txt", "r", stdin);
//
//	cin >> N >> ws; // ws: clear input buffer
//
//	while (N--) {
//		int cursor = 0, head = 1, left, right; // posiition of cursor, empty LL node index.
//		int pre[MX], nex[MX];
//		char dat[MX] = {0};
//		string str;
//
//		fill(pre, pre + MX, -1);
//		fill(nex, nex + MX, -1);
//
//		getline(cin, str);
//
//		for (int i = 0; i < str.size(); i++) {
//			char cur_ch = str[i];
//			switch(cur_ch) {
//				case'<':
//					if (pre[cursor] != -1) cursor = pre[cursor];
//					break; 
//				case'>':
//					if (nex[cursor] != -1) cursor = nex[cursor];
//					break; 
//				case'-':
//					if (pre[cursor] == -1) 
//						break;
//					left = pre[cursor], right = nex[cursor];
//					pre[cursor] = nex[cursor] =  -1;
//
//					nex[left] = right;
//					if (right != -1) pre[right] = left;
//					cursor = left;
//					break; 
//
//				default:
//					left = cursor, right = nex[cursor];
//					dat[head] = str[i];
//					pre[head] = left;
//					nex[head] = right;
//
//					nex[left] = head;
//					if (right != -1) pre[right] = head;
//
//					cursor = head++;
//					break;
//			}
//		}
//
//		int cur_pos = 0;
//		while (nex[cur_pos]!=-1) {
//			cur_pos = nex[cur_pos];
//			cout << dat[cur_pos];
//		}
//		cout << "\n";
//	}
//
//	return 0;
//}