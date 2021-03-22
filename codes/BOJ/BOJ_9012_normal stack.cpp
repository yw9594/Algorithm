///*
//	개요 : 백준 9012번 괄호
//	요약 :
//		stack을 사용해 구현해본다.
//	내용 :
//		한 줄만 작성하는 에디터를 만들어본다.
//	핀포인트 :
//*/
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//	std::ios::sync_with_stdio(false);
//	// cin.tie(0);
//	
//	int N;
//	cin >> N;
//	while (N--) {
//		int head = -1, flag=true;
//		string str;
//		cin >> str;
//
//		for (int i = 0; i < str.size() && true; i++) {
//			if (str[i] == '(') head++;
//			else if (head > -1) {
//				head--;
//			}
//			else flag = false;
//		}
//		if (head != -1) flag = false;
//
//
//		if (flag) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}