///*
//	개요 : circle queue 구현
//	요약 :
//		원형 큐를 구현해본다.
//
//	핀포인트 :
//		1) 링크스리스트처럼 첫 칸을 비우면 구현이 간단해진다. (_front = _rear =0;)
//		2) modulo 연산을 사용해 원형 상태를 구현한다. 
//		3) modulo를 사용할 경우 조건은 다음과 같다.
//			1) empty : _front==_rear일 경우 empty
//			2) push  : (rear+1)%MX != _front 일 경우 삽입 가능 다음 _rear = (_rear+1)%MX;
//			3) pop   : _front != rear일 경우 pop 가능. 다음 _front = (_front+1)%MX;
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