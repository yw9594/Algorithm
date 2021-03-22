//#include <iostream>
//
//using namespace std;
//
//int head = -1;
//char stk[2001];
//
//int main(void) {
//	int N = 1, ans=0;
//	char ch;
//
//	freopen("input.txt", "r", stdin);
//
//	while ((ch = getchar()) != EOF) {
//		
//		if (ch == '-') break;
//		else if (ch == '\n') { // end of sentence. calculate min.
//			// guarantee that input length is even.
//			while (head != -1) {
//				char a = stk[head--];
//				char b = stk[head--];
//
//				if (a == b) // case 1: }} or case2 : {{ 
//					ans += 1;
//				else // case 2: }{
//					ans += 2;
//			}
//			printf("%d. %d\n", N, ans);
//
//			ans = 0;
//			N++;
//			head = -1;
//		}
//		else if (ch == '{') stk[++head] = ch;
//		else if(ch=='}'){
//			if (stk[head] == '{') head--; // well matched. pop.
//			else 
//				// push current character for checking unmatched after read sentence.
//				// This can be that stack, or stack top is not matched..  
//				stk[++head] = ch;
//		}
//		
//	}
//
//
//	return 0;
//}