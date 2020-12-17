//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int MX = 100002;
//int dat[MX], q_size = 0, _front=0, _rear=0;
//
//void push(int x) {
//	int next_rear = (_rear + 1) % MX;
//	if (next_rear != _front) {
//		dat[next_rear] = x;
//		_rear = next_rear;
//		q_size++;
//	}
//	return;
//}
//int pop() {
//	if (_front != _rear) {
//		_front = (_front + 1) % MX;
//		q_size--;
//		return dat[_front];
//	}
//	else return -1;
//}
//int empty() {
//	if (_front == _rear) return 1;
//	return 0;
//}
//int front() {
//	if (_front != _rear) return dat[(_front+1)%MX];
//	return -1;
//}
//int back() {
//	if (_front != _rear) return dat[_rear];
//	return -1;
//}
//
//
//int main(void) {
//	int N;
//	string cmd;
//
//	std::ios::sync_with_stdio(false);
//	//cin.tie(0);
//
//	cin >> N;
//
//	while (N--) {
//		cin >> cmd;
//
//		if (cmd == "push") {
//			int x; cin >> x; push(x);
//		}
//		else if (cmd == "pop") {
//			printf("%d\n", pop());
//		}
//		else if (cmd == "size") {
//			printf("%d\n", q_size);
//		}
//		else if (cmd == "empty") {
//			printf("%d\n", empty());
//		}
//		else if (cmd =="front") {
//			printf("%d\n", front());
//		}
//		else if (cmd=="back") {
//			printf("%d\n", back());
//		}
//	}
//	
//	return 0;
//}