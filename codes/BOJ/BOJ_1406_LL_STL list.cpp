///*
//	개요 : 백준 1406번 에디터
//	요약 :
//		STL list를 사용해 문제를 해결한다.
//	내용 :
//		한 줄만 작성하는 에디터를 만들어본다.
//	핀포인트 :
//		1. LL 구조에 root 노드를 NULL로 작성하면 insert와 erase에서 if문이 많이 사라진다.
//			단, 반드시 root node가 지워져선 안된다.
//
//		2. 1의 이유로 erase와 insert 부분에서 next node가 NULL일 가능성만 고려하면된다.
//			prev node는 root node의 존재로 root를 제외한 노드는 항상 NULL이 될 수 없다.
//			반대로 말하면 prev node가 NULL이라면 반드시 root node이다.
//	오류 발생
//		
//*/
//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int main(void) {
//	int t = 0,  N, len;
//	string initText;
//	list<char> LL;
//	list<char>::iterator cursor;
//
//	cin >> initText >> N;
//	for (int i = 0; i < initText.size(); i++) LL.push_back(initText[i]);
//	cursor = LL.end();
//
//	printf("%p\n", cursor);
//	printf("%p\n", LL.begin());
//	printf("%p\n", LL.end());
//	printf("%d\n", LL.size());
//
//	while(N--){
//		char cmd;
//		cin >> cmd;
//		switch (cmd) {
//			case 'L': 
//				if (cursor != LL.begin()) cursor--;
//				break;	
//			case 'D': 
//				if (cursor != LL.end()) cursor++;
//				break;	
//			case 'B': 
//
//				if (cursor != LL.begin()) 
//					cursor = LL.erase(--cursor);
//				break;
//			case 'P':
//				cin >> cmd;
//				cursor = LL.insert(cursor, cmd);
//				cursor++;
//				break;
//		}
//	}
//
//	for (auto& c : LL) printf("%c", c);
//	printf("\n");
//
//	return 0;
//}