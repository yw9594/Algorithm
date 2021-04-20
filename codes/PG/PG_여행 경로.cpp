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
struct Ticket {
	string dest;
	bool checked;
};

bool check(vector<string> & answer, vector<string> & path) {
	if(answer.size()==0) return true;
	else {
		for(int i=0; i<answer.size(); i++) {
			int comp = path[i].compare(answer[i]);
			if(comp) return comp<0 ? true : false;
		}
	}
	return false;
}

void DFS(string & cur_node, int n, vector<string> & answer, vector<string> & path, unordered_map<string, vector<Ticket>> & mat){
	path.push_back(cur_node);

	if(path.size()==n) {
		if(check(answer, path)) answer.assign(path.begin(), path.end());
		path.pop_back();
		return;
	}

	for(Ticket & nn : mat.find(cur_node)->second) {
		if(!nn.checked) {
			nn.checked=true;
			DFS(nn.dest, n, answer, path, mat);
			nn.checked=false;
		}
	}

	path.pop_back();

	return;
}	

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

	set<string> nodes;
	for(auto & e : tickets) {
		nodes.insert(e[0]);
		nodes.insert(e[1]);
	}

	unordered_map<string, vector<Ticket>> mat;
	for(auto & n : nodes) mat.insert({n, vector<Ticket>()});

	for(int i=0; i<tickets.size(); i++) {
		string & a = tickets[i][0], & b = tickets[i][1];
		auto it = mat.find(a);
		it->second.push_back({b, false});
	}

	int n = tickets.size(); // 티켓을 모두 사용하면 경로에 포함된 노드 수 는 n+1
	vector<string> path;
	string begin = "ICN";
	DFS(begin, n+1, answer, path, mat);

    return answer;
}

int main(void) {
	showLine("start");
	// solution({{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}});
	// solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}});
	// ["ICN","ATL","SFO","ATL","ICN","SFO"]
	// ["ICN","ATL","ICN","SFO","ATL","SFO"] // 정답
	// solution({{"ICN", "JFK"}});
	// solution({{"ICN", "B"}, {"B", "ICN"}});
	solution({{"ICN", "A"}, {"ICN", "B"},{"B", "C"},{"A", "ICN"}});

	showLine("done");
	return 0;
}