//#include <iostream>
//
//using namespace std;
//
//int stk[101], head = -1;
//
//inline int toIdx(char& ch) {
//	if (ch == '(' || ch == ')') return 0;
//	else if (ch == '[' || ch == ']') return 1;
//	else return -1;
//}
//
//int main(void) {
//	int len = 0;
//	char cur_ch;
//	bool flag = true;
//
//	freopen("input.txt", "r", stdin);
//
//	while ((cur_ch=getchar()) != EOF) {
//		if (!flag && cur_ch != '.' || cur_ch=='\n') continue;
//		
//		if (cur_ch == '.') { // end of sentence.
//			if (len == 0) {
//				break;
//			}
//
//			if (head != -1 || !flag) printf("no\n");
//			else printf("yes\n");
//
//			flag = true;
//			head = -1;
//			len = 0;
//		}
//		else {
//			len++;
//			if (cur_ch == '(' || cur_ch == '[')
//				stk[++head] = toIdx(cur_ch);
//			else if (cur_ch == ')' || cur_ch == ']') {
//				if ((stk[head] != toIdx(cur_ch)) || head == -1) // not matched or empty stack. 
//					flag = false;
//				else
//					head--;
//			}
//		}
//	}
//	return 0;
//}