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
//
//using namespace std;
//
//int main(void) {
//	list<char> LL(3, 'a');
//	list<char>::iterator iter = LL.begin();
//
//
//	cout << *iter << *LL.begin() << endl;
//	
//
//	return 0;
//}