#include <iostream>

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

#define SIZE 10

struct CircularQueue{
	int db[SIZE+1]; // 한 칸은 비워둔다.
	int start, end;

	CircularQueue():start(0), end(0){};
	void push(int data) {
		if(!full()) {
			db[(end = (end+1) % (SIZE+1))]=data;
			return;
		}

		fputs ("queue is full ",stderr);
		abort();
	}
	void pop(){
		if(!empty()) {
			start = (start+1) % (SIZE+1);
			return;
		}
		fputs ("queue is empty ",stderr);
		abort();
	}
	int front(){
		if(!empty()) return db[(start+1) % (SIZE+1)];
		fputs ("queue is empty ",stderr);
		abort();
	}
	bool empty(){
		if(start==end) return true;
		return false;
	}
	bool full() {
		if((end+1)%(SIZE+1) == start) return true; 
		return false;
	}
	

};

int main(void) {
	CircularQueue cq;
	for(int i=0; i<10; i++) {
		cout <<i<< " is pushed"<<"\n";
		cq.push(i);
	}
	// cq.push(10); // queue full error

	while(!cq.empty()) {
		cout << cq.front()<<"\n";
		cq.pop();
	}
	// cq.pop(); // queue empty error

	return 0;
}