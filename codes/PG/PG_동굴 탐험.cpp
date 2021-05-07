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

void dfs(int c_n, vector<set<int>> & mat, vector<int> & parent, vector<int> & pushed) {
	pushed[c_n] = 1;
	for(auto & n_n : mat[c_n]) {
		if(!pushed[n_n]){
			parent[n_n] = c_n;
			dfs(n_n, mat, parent, pushed);
		}
	}
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer;

	// 인접리스트 생성
	vector<set<int>> mat(n, set<int>());
	for(vector<int> & edge : path) {
		int a = edge[0], b = edge[1];
		mat[a].insert(b);
		mat[b].insert(a);
	}

	// 경유 조건
	vector<int> cond(n, -1); // cond[i]=j : j번째 노드를 방문하기 위해선 i 노드를 먼저 방문해야. 
	for(vector<int> & ord : order) {
		int a = ord[0], b = ord[1];
		cond[a] = b;
	}

	// lock 설정
	vector<int> lock(n, 0); // lock[i]=1 : i 노드는 cond[k]=i인 k 노드를 방문해야 큐에 삽입될 수 있음.
	for(auto & con : cond) {
		if(con != -1) lock[con]=1;
	}

	// 부모 노드 체크
	vector<int> parent(n, -1);
	vector<int> pushed(n, 0);

	dfs(0, mat, parent, pushed);

	// 탐색 시작
	int cnt=0;
	queue<int> q;
	pushed = vector<int>(n, 0);

	if(lock[0]) return false;

	q.push(0);
	pushed[0] = 1;

	while(!q.empty()){
		int c_n = q.front(); q.pop();
		cnt++;
		// 현재 노드가 선경유 노드면 해당 노드의 lock을 해제.
		if(cond[c_n] != -1) {
			lock[cond[c_n]]=0;
			// 부모가 pushed된 적이 있으면 삽입
			if(pushed[parent[cond[c_n]]]) {
				q.push(cond[c_n]);
				pushed[cond[c_n]]=1;
			}
		}

		// 현재 노드에서 갈수 있는 다른 노드를 삽입.
		for(auto & n_n : mat[c_n]) {
			if(!pushed[n_n] && !lock[n_n]) {
				q.push(n_n);
				pushed[n_n]=1;
			}
		}
	}
	answer = (cnt==n ? true : false);
    return answer;
}

int main(void) {
	showLine("start");

	// cout << solution(9, {{0,1}, {0,3}, {0,7}, {8,1}, {3,6}, {1,2}, {4,7}, {7,5}}, {{8,5}, {6,7}, {4,1}}) <<"\n"; // true
	// cout << solution(4, {{0,1}, {0, 2}, {1, 3}}, {{1, 2}, {2, 1}}) <<"\n";
	// cout << solution(6, {{0,1}, {0, 2}, {1, 3}, {2, 4}}, {{3, 2}, {4, 1}}) <<"\n";
	cout << solution(2, {{0,1}}, {{1, 0}}) <<"\n";
	cout << solution(6, {{0,1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}}, {{3, 1}, {5, 4}}) <<"\n";


	showLine("done");
	return 0;
}