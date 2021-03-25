#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

#include <string>
#include <cstring>
#include <sstream>   // ex) stringstream

#include <cmath>    
#include <cctype>    // ex) isdigit..

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것

struct Node{
	bool flag;  		// 현재 위치의 문자가 어떤 단어의 끝인지 여부를 체크.
	Node * child[10];	// 다음 숫자 노드의 주소(0~9) 
	Node():flag(false){
		for(auto & e : child) e =NULL;
	}
};
struct Trie{
	Node * root;
	Trie() { root = new Node();}
	~Trie() {destroy(root);}
	
	int charToInt(char & c) {return c-'0';}
	bool push(string & phoneNumber){
		int idx = 0, lim=phoneNumber.size();
		bool ret = true;
		Node * cur_node = root;

		while(idx!=lim && ret){
			int c= charToInt(phoneNumber[idx]);
			if(cur_node->flag) ret=false;						 			 // 만약, 현재 삽입하고 있는 전화번호에 접두사에 해당하는 전화번호가 존재한다면, 불가능하다.
			if(cur_node->child[c]==NULL) cur_node->child[c] = new Node();    // 만약, 현재 검사하고 있는 문자가 처음 발견된 문자라면 노드 추가
			cur_node = cur_node->child[c];									 // 다음 문자로 이동
			idx++;
		}
		cur_node->flag=true;

		return ret;
	}
	void destroy(Node * cur_node){
		for(int i=0; i<10; i++)
			if(cur_node->child[i])
				destroy(cur_node->child[i]);
		delete cur_node;
	}
};
struct Pred{
	bool operator()(const string & a, const string & b){return a.size()<b.size();}
};

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);
	
	// showLine("start");
	// showLine("done");

	int T; 
	cin >> T;
	while(T--) {
		int N;
		vector<string> phones;

		cin>> N;

		phones.resize(N);
		for(int i=0; i<N; i++) cin>>phones[i];
		sort(phones.begin(), phones.end(), Pred());
		
		bool ans = true;
		Trie tree;
		for(int i=0; i<N && ans; i++) 
			ans = tree.push(phones[i]);
		
		cout << (ans ? "YES" : "NO") <<"\n";
	}

	return 0;
}