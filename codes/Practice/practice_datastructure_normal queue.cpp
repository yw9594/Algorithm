#include <iostream>
#include <cstdlib>

using namespace std;

const int MX = 1000000;
int dat[MX];
int _front=0, _rear=0;

void push(int x) { 
	if (_rear + 1 < MX) dat[++_rear] = x;
	else {
		printf("# system : push : Queue is full\n");
		abort();
	}
}
void pop() { 
	if(_front!=_rear)++_front;
	else { 
		printf("# system : pop : Queue is empty\n");
		abort();
	}
}
int front() { 
	if (_front != _rear) return dat[_front + 1];
	else {
		printf("# system : front : Queue is empty\n");
		abort();
	}
}
int back() { 
	if (_front != _rear) return dat[_rear];
	else {
		printf("# system : back : Queue is empty\n");
		abort();
	}
}
void show() {
	for (int i = _front + 1; i <= _rear; i++) printf("%d ", dat[i]);
	printf("\n");
}

int main(void) {

	show();
	for (int i = 0; i < 10; i++) push(i);
	show();
	for (int i = 0; i < 9; i++) pop();
	show();
	printf("front: %d back: %d\n", front(), back());


	return 0;
}