#include <iostream>

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것

struct Node{
	int data;
	Node * left, *right;
	Node():left(NULL), right(NULL){}; // root 노드는 left가 NULL
	Node(int _data, Node * _left=NULL, Node * _right=NULL) : data(_data), left(_left), right(_right) {}
};	
struct DualLinkedList {
	int size;
	Node * front , *rear;
	DualLinkedList():size(0), front(NULL), rear(NULL){}
	~DualLinkedList(){if(front) delete front;}
	void create(){front=rear=new Node();}
	void push(int data) {
		Node * new_node = new Node(data, rear, NULL);
		rear->right = new_node;
		rear=new_node;
		size++;
	}
	void insert(int idx, int data){
		if(size==0 || idx>=size || idx<0) {
			cerr<<"invalid idx"<<"\n";
			abort();
		}
 
		int i = -1;
		Node * cur_node = front;

		while(i!=idx) {
			i++;
			cur_node = cur_node->right;
		}
		
		Node * new_node = new Node(data, cur_node->left, cur_node);
		cur_node->left->right = new_node;
		cur_node->left = new_node;
		size++;
	}
	Node * find(int data) {
		Node * cur_node = front;

		while(cur_node->right!=NULL){
			cur_node = cur_node->right;
			if(data==cur_node->data) break;
		}
		if(data==cur_node->data) return cur_node;
		else return NULL;
	}
	void erase(Node * del_node){
		del_node->left->right = del_node->right;
		if(del_node->right != NULL )del_node->right->left = del_node->left;
		delete del_node;
		size--;
	}
	void show() {
		Node * cur_node =front;
		while(cur_node->right!=NULL){
			cur_node = cur_node->right;
			cout << cur_node->data <<" ";
		}
		cout<<"\n";
	}
};


int main(void) {
	// test
	DualLinkedList ll;

	ll.create();							// create 테스트
	for(int i=0; i<10; i++) ll.push(i);		// push 테스트
	ll.insert(0, 10);						// insert 테스트
	ll.show();

	cout << ll.size<<"\n";					// size 테스트 

	auto it = ll.find(10);					// find 테스트
	if(it!=NULL) cout<< "데이터 있음"<<"\n";
	else cout<< "데이터 없음"<<"\n";

	ll.erase(it);							// erase 테스트
	cout << ll.size <<"\n";
	ll.show();

	return 0;
}