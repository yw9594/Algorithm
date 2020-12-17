///*
//	���� : ���� 1406�� ������
//	��� :
//		STL list�� ����� ������ �ذ��Ѵ�.
//	���� :
//		�� �ٸ� �ۼ��ϴ� �����͸� ������.
//	������Ʈ :
//		1. LL ������ root ��带 NULL�� �ۼ��ϸ� insert�� erase���� if���� ���� �������.
//			��, �ݵ�� root node�� �������� �ȵȴ�.
//
//		2. 1�� ������ erase�� insert �κп��� next node�� NULL�� ���ɼ��� ����ϸ�ȴ�.
//			prev node�� root node�� ����� root�� ������ ���� �׻� NULL�� �� �� ����.
//			�ݴ�� ���ϸ� prev node�� NULL�̶�� �ݵ�� root node�̴�.
//	���� �߻�
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