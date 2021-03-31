#include <iostream>
#include <vector>


using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것

struct Node{
	int data;
	Node *left, *right;
	Node(){}
	Node(int _data, Node * _left=NULL, Node * _right=NULL) : data(_data), left(left), right(_right) {} 
};

struct BinaryTree{
	Node * root;
	BinaryTree() {root = NULL;}
	~BinaryTree() {if(root) delete root;}
	void push(int data) {
		if(!root) root = new Node(data);
		else{
			Node * cur_node = root;
			while(1) {
				if(data < cur_node->data) { // 현재 노드보다 값이 작음
					if(cur_node->left == NULL){ 
						cur_node->left = new Node(data);
						break;
					}
					else cur_node = cur_node->left; 
				} 
				else { // 현재 노드보다 값이 큼
					if(cur_node->right == NULL){
						cur_node->right = new Node(data);
						break;
					}
					else cur_node = cur_node->right; 
				}
			}
		}
	}
	Node * find(int data){ 
		Node * cur_node = root;
		while(cur_node->data!=data){
			if(data < cur_node->data) {
				if(cur_node->left == NULL){ 
					return NULL; // 데이터 없음
				}
				else cur_node = cur_node->left; 
			}
			else{
				if(cur_node->right == NULL){ 
					return NULL; // 데이터 없음
				}
				else cur_node = cur_node->right; 
			}			
		}
		return cur_node;
	}
	void order(int idx){ // -1, 0, 1 : pre, in, post
		if(idx==0) inOrder(root);
		else if(idx == -1) preOrder(root);
		else if(idx == 1) postOrder(root);
		cout <<"\n";
	}
	void inOrder(Node * cur_node) {
		if(cur_node->left) inOrder(cur_node->left);
		cout << cur_node->data <<" ";
		if(cur_node->right) inOrder(cur_node->right);

	}
	void preOrder(Node * cur_node) {
		cout << cur_node->data <<" ";
		if(cur_node->left) preOrder(cur_node->left);
		if(cur_node->right) preOrder(cur_node->right);

	}
	void postOrder(Node * cur_node) {
		if(cur_node->left) postOrder(cur_node->left);
		if(cur_node->right) postOrder(cur_node->right);
		cout << cur_node->data <<" ";
	}
};

int main(void) {
	vector<int> arr = {5,2,7,1,3,6,8};
	BinaryTree tree;

	for(auto & e : arr) tree.push(e); 						// push test
	for(auto & e : arr) cout << tree.find(e)->data<<" ";	// find test
	cout <<"\n";

	tree.order(-1);
	tree.order(0);
	tree.order(1);

	return 0;
}