//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int MX = 200002;
//int dat[MX], q_size = 0, _front=100000, _rear=100000;
//
//void push_front(int x) {
//	dat[_front--] = x;	q_size++;
//	return;
//}
//void push_back(int x) {
//	dat[++_rear] = x;	q_size++;
//	return;
//}
//int pop_front() {
//	if (_front == _rear) return -1;
//	q_size--;
//	return dat[_front++ + 1];
//}
//int pop_back() {
//	if (_front == _rear) return -1;
//	q_size--;
//	return dat[_rear--];
//}
//int size() { 
//	return q_size; 
//}
//int empty() {
//	if (_front == _rear) return 1;
//	return 0;
//}
//int front() {
//	if (_front != _rear) return dat[(_front+1)];
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
//		if (cmd == "push_front") {
//			int x; cin >> x; 
//			push_front(x);
//		}
//		else if (cmd == "push_back") {
//			int x; cin >> x;
//			push_back(x);
//		}
//		else if (cmd == "pop_front") {
//			printf("%d\n", pop_front());
//		}
//		else if (cmd == "pop_back") {
//			printf("%d\n", pop_back());
//		}
//		else if (cmd == "size") {
//			printf("%d\n", size());
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