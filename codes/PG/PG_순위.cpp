#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

int check(int n, int i, vector<vector<int>> & edge) {
	int ret=0;

	int pushed[101]={0,};
	queue<int> q;
	
	q.push(i);
	pushed[i]=1;

	while(!q.empty()) {
		int cur_node = q.front();q.pop();
		for(auto & e : edge[cur_node]){
			if(!pushed[e]) {
				ret++;
				q.push(e);
				pushed[e]=1;
			}
		}
	}

	return ret;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

	vector<vector<int>> out_mat(n+1, vector<int>()); // i 노드에게 이긴 사람 저장
	vector<vector<int>> in_mat(n+1, vector<int>());  // i 노드에게 진 사람 저장

	for(auto & e : results){
		int winner=e[0], loser=e[1];
		out_mat[loser].push_back(winner);
		in_mat[winner].push_back(loser);
	}

	for(int i=1; i<=n; i++) {
		int loser=0, winner=0;
		
		loser = check(n, i, in_mat);
		winner = check(n, i, out_mat);

		if(loser+winner==n-1) answer++;
	}


    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");

	showLine("done");
	return 0;
}