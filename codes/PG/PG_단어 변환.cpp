#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////
struct Node{
	int node;
	string word;
	int cnt;
};

bool check(string & a, string & b) {
	int n=a.size(), cnt=0;

	for(int i=0; i<n; i++) {
		if(a[i]!=b[i]) cnt++;
	}

	return cnt==1 ? true : false;
}


int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int beg;
	
	words.push_back(begin);

	int n = words.size();
	vector<Node> nodes;
	for(int i=0; i<n; i++) {
		if(!words[i].compare(begin)) beg = i;
		nodes.push_back({i, words[i], 0});
	}

	vector<vector<Node>> mat(n, vector<Node>());
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(check(words[i], words[j])){
				mat[i].push_back(nodes[j]);
				mat[j].push_back(nodes[i]);
			}
		}
	}

	queue<Node> q;
	vector<bool> pushed(n, 0);
	
	q.push({beg, begin, 0});
	pushed[beg]=1;

	while(!q.empty()) {
		Node cur_node = q.front(); q.pop();

		if(!cur_node.word.compare(target)) {
			answer = cur_node.cnt;
			break;
		}

		for(auto & nn : mat[cur_node.node]) {
			if(!pushed[nn.node]) {
				q.push({nn.node, nn.word, cur_node.cnt+1});
				pushed[nn.node]=1;
			}
		}
	}
    return answer;
}

int main(void) {
	showLine("start");
	solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
	showLine("done");
	return 0;
}