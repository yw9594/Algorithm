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

#include "infos.h"

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것.
struct Node{
	int flag, cnt;
	Node * child[26];
	Node() {
		cnt=0;
		flag = false;
		for(auto & e : child) e=NULL;
	}
};
struct Tree {
	Node*root;
	Tree(){	root = new Node();}
	int charToInt(char & c){return c-'0';}
	void push(string & word, int is_reverse){
		int idx = is_reverse > 0 ? 0 : word.size()-1, 
			lim = is_reverse > 0 ? word.size() : -1;
		Node * cur_node = root;	
		while(idx!=lim) {
			int c = charToInt(word[idx]);
			if(cur_node->child[c] == NULL) cur_node->child[c] = new Node();
			cur_node->cnt++;
			cur_node =  (cur_node->child)[c];
			idx += is_reverse;
		}
		cur_node->flag = true;
	}
	int find(string & query){
		int cnt=0;
		findRecursive(query, root, cnt, 0);
		return cnt;
	}
	void findRecursive(string & query, Node * cur_node, int & cnt, int idx) {
		if(idx==query.size()){
			if(cur_node->flag)
				cnt++;
		}
		else if(query[idx]=='?') {
			cnt+=cur_node->cnt;
		}
		else{
			int c = charToInt(query[idx]);
			if((cur_node->child)[c]!=NULL)
				findRecursive(query, (cur_node->child)[c], cnt, idx+1);
		}
	}

};


vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	Tree tree[10001], rtree[10001];

	for(auto & w : words) {
		tree[w.size()].push(w, 1);
		rtree[w.size()].push(w, -1);
	}

	for(auto & q : queries) {
		int cnt;
		if(q[0]=='?'){
			reverse(q.begin(), q.end());
			cnt = rtree[q.size()].find(q);
			reverse(q.begin(), q.end());
		}
		else{
			cnt = tree[q.size()].find(q);
		}
		answer.push_back(cnt);
	}

	return answer;
}

int main(void) {
	// input
	/*freopen("input.txt", "r", stdin);
	std::istream>::sync_with_stdio(false);
	cin.tie(NULL);
	*/
	vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
	vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};

	showLine("start");
	vector<int> ans = solution(words, queries);
	show1dArray(ans);

	showLine("done");
	return 0;
}