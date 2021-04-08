#include <iostream>
#include <algorithm>
#include <vector>

#include "../infos.h"

using namespace std;

// 프로그래머스 문제 풀이 시 전역변수는 solution 변수 내에서 초기화한다.
struct Node {
	int n, x, y;
	Node * left, *right;
	Node(int _n, int _x, int _y, Node * _left=NULL, Node * _right=NULL) : n(_n), x(_x), y(_y), left(_left), right(_right) {}
	Node(const Node & arg) {
		this->n = arg.n; this->x = arg.x; this->y = arg.y;
	}
	bool operator=(const Node & arg) {
		this->n = arg.n; this->x = arg.x; this->y = arg.y;
	}
	bool operator<(const Node & arg) const{
		if(this->y==arg.y) return this->x < arg.x;
		return this->y > arg.y;
	}
};
struct Tree{
	Node * root;
	Tree(Node node) {	
		root = new Node(node);
	}
	~Tree() {if(root) delete root;}

	void push(Node & node) {
		Node * cur_node = root;
		while(1) {
			if(node.x < cur_node->x) {
				if(cur_node->left==NULL) { cur_node->left = new Node(node); break;}
				else cur_node = cur_node->left;
			}
			if(node.x > cur_node->x) {
				if(cur_node->right==NULL) {cur_node->right = new Node(node); break;}
				else cur_node = cur_node->right;
			}
		}
	}
	vector<int> order(int flag) {
		vector<int> ret;
		if(flag==0) preoder(root, ret);
		else if(flag==1) postoder(root, ret);
		return ret;
	}
	void preoder(Node * cur_node, vector<int> & ret) {
		ret.push_back(cur_node->n);
		if(cur_node->left) preoder(cur_node->left, ret);
		if(cur_node->right) preoder(cur_node->right, ret);
	}
	void postoder(Node * cur_node, vector<int> & ret) {
		if(cur_node->left) postoder(cur_node->left, ret);
		if(cur_node->right) postoder(cur_node->right, ret);
		ret.push_back(cur_node->n);
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = vector<vector<int>>(2, vector<int>());
	vector<Node> nodes;

	for(int i=0; i<nodeinfo.size(); i++) nodes.push_back(Node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
	sort(nodes.begin(), nodes.end());
	
	Tree tree(nodes[0]);
	for(int i=1; i<nodes.size(); i++) tree.push(nodes[i]);

	answer[0] = tree.order(0);
	answer[1] = tree.order(1);

    return answer;
}

int main(void) {

	showLine("start");	
	show2dArray(solution({{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}}));
	showLine("done");	

	return 0;
}