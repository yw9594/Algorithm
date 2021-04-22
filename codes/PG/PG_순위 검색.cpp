#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <string>
#include <cstring>
#include <sstream>   // ex) stringstream

#include <cmath>    
#include <cctype>    // ex) isdigit..

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

vector<string> split(string& str, char delim = ' ') {
	vector<string> toks;
	stringstream ss(str);
	string tok;

	while (getline(ss, tok, delim)) toks.push_back(tok);

	return toks;
}
vector<string> queryParser(string & query) {
	vector<string> toks = split(query);
	vector<string> ret;
	for(int i=0; i<toks.size(); i++) {
		if(i==1 || i==3 || i==5) continue;
		ret.push_back(toks[i]);
	}
	return ret;
}

struct Node {
	vector<int> score;		// 점수 : 사람 수 
	Node * childs[3]; 	// 최대 3개의 child까지 가짐
	Node(){
		for(int i=0; i<3; i++) childs[i]=NULL;
	}
};

struct Tree{
	Node * root;
	unordered_map<string, int> key_table;
	Tree() {
		root = new Node();
		key_table.insert({"cpp", 0});
		key_table.insert({"java", 1});
		key_table.insert({"python", 2});
		key_table.insert({"backend", 0});
		key_table.insert({"frontend", 1});
		key_table.insert({"junior", 0});
		key_table.insert({"senior", 1});
		key_table.insert({"pizza", 0});
		key_table.insert({"chicken", 1});
		init(0, root); // 트리 구조 생성
	}
	~Tree() {if(root) delete root;}
	void init(int idx, Node * cur_node){
		// 마지막 점수는 직접 저장한다.
		if(idx==4) {
			cur_node->score=vector<int>();
			return;
		}
		// 언어는 3개까지 존재한다.
		else {
			for(int i=0 ; i < (idx==0? 3 : 2) ; i++)  {
				(cur_node->childs)[i]= new Node();
				init(idx+1, cur_node->childs[i]);
			}
		}
	}
	void push(vector<string> & toks) {
		Node * cur_node = root;
		for(int idx=0; idx<4; idx++) {
			int key = key_table.find(toks[idx])->second;		
			cur_node = cur_node->childs[key];	
		}

		int score = stoi(toks[4]);
		vector<int> & scores = (cur_node->score);
		scores.push_back(score);	
	}
	void validate(int idx, Node * cur_node) {
		if(idx==4) {
			vector<int> & scores = (cur_node->score);	
			sort(scores.begin(), scores.end());
			return;
		}
		else {
			for(int i=0 ; i < (idx==0? 3 : 2) ; i++)  {
				validate(idx+1, cur_node->childs[i]);
			}
		}
	}

	int counting(vector<string> & query){
		int ret = search(query, 0, root);
		return ret;
	}

	int search(vector<string> & toks, int idx, Node * cur_node){
		if(idx==4) {
			int score = stoi(toks[idx]);
			vector<int> & scores = (cur_node->score);
			auto it = lower_bound(scores.begin(), scores.end(), score);
			return scores.end()-it;
		}
		if(!toks[idx].compare("-")) {
			int ret=0;
			for(int i=0; i<(idx==0 ? 3 : 2); i++) ret += search(toks, idx+1, cur_node->childs[i]);
			return ret;
		}
		else {
			int key = key_table.find(toks[idx])->second;	
			return search(toks, idx+1, cur_node->childs[key]);
		}
	}
};


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
	// db
	vector<vector<string>> parsed_info;
	for(auto & i : info) parsed_info.push_back(split(i));

	Tree tree;
	for(int i=0; i<parsed_info.size(); i++) tree.push(parsed_info[i]);
	tree.validate(0, tree.root);
	
	// query
	for(auto & q : query) {
		vector<string> toks = queryParser(q);
		answer.push_back(tree.counting(toks));
	}

    return answer;
}

int main(void) {
	showLine("start");

	show1dArray(solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}, 
				{"java and backend and junior and pizza 100",
				"python and frontend and senior and chicken 200",
				"cpp and - and senior and pizza 250",
				"- and backend and senior and - 150",
				"- and - and - and chicken 100",
				"- and - and - and - 150"}));


	// show1dArray(solution({"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"}, 
	// 			{"java and backend and junior and pizza 100"}));


	showLine("done");
	return 0;
}