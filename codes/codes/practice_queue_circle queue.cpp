///*
//	���� : circle queue ����
//	��� :
//		���� ť�� �����غ���.
//
//	������Ʈ :
//		1) ��ũ������Ʈó�� ù ĭ�� ���� ������ ����������. (_front = _rear =0;)
//		2) modulo ������ ����� ���� ���¸� �����Ѵ�. 
//		3) modulo�� ����� ��� ������ ������ ����.
//			1) empty : _front==_rear�� ��� empty
//			2) push  : (rear+1)%MX != _front �� ��� ���� ���� ���� _rear = (_rear+1)%MX;
//			3) pop   : _front != rear�� ��� pop ����. ���� _front = (_front+1)%MX;
//
//*/
//
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//const int MX = 20;
//int dat[MX];
//int _front = 0, _rear = 0;
//
//void push(int x) {
//	int next_rear = (_rear + 1) % MX;
//
//	if (next_rear != _front) {
//		dat[next_rear] = x;
//		_rear = next_rear;
//	}
//	else {
//		printf("# system : push : Queue is full\n");
//	}
//}
//void pop() {
//	if (_rear != _front) {
//		_front = (_front+1) % MX;
//	}
//	else {
//		printf("# system : pop : Queue is empty\n");
//	}
//}
//
//void show() {
//	int i = _front;
//	while (i != _rear) {
//		i = (i + 1) % MX;
//		printf("%d ", dat[i]);
//	}
//	printf("\n");
//}
//
//int main(void) {
//
//	for (int i = 0; i < 20; i++) push(i);
//	show();
//	printf("## %d %d\n", _front, _rear);
//
//	for (int i = 0; i < 20; i++) pop();
//	show();
//	printf("## %d %d\n", _front, _rear);
//
//	for (int i = 0; i < 20; i++) push(i);
//	show();
//	printf("## %d %d\n", _front, _rear);
//
//
//	for (int i = 0; i < 20; i++) pop();
//	show();
//	printf("## %d %d\n", _front, _rear);
//	
//
//	return 0;
//}