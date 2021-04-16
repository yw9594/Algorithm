#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

struct Elem{
	int node, cnt; // 노드 번호, 경로 길이
};

int solution(int n, vector<vector<int>> edge) {
	vector<vector<int>> mat(n+1, vector<int>());


	// self loop, 간선 중복 미처리
	for(int i=0; i<edge.size(); i++) {
		int a = edge[i][0], b = edge[i][1];
		
		mat[a].push_back(b);
		mat[b].push_back(a);
	}

	
	queue<Elem> q;
	int pushed[200000] = {0}, max_cnt=0;
    int answer = 0;

	q.push({1, 0});
	pushed[1] = 1;

	while(!q.empty()){
		int cur_node = q.front().node;
		int cur_cnt = q.front().cnt;
		q.pop();

		cout << cur_node<<" ";
		if(cur_cnt > max_cnt) {
			max_cnt=cur_cnt;
			answer=1;
		}
		else if (cur_cnt==max_cnt) answer++;

		for(auto & nn : mat[cur_node]) {
			if(!pushed[nn]){
				q.push({nn, cur_cnt+1});
				pushed[nn]=1;
			}
		}
	}
	cout <<"\n";
	cout << answer<<"\n";

    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");
	solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
	showLine("done");
	return 0;
}