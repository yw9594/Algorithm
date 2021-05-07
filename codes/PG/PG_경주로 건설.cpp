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

#define INF 99999999

struct Node{
	int i, j, c; 
	int dir; // 이전 방향(수직 : 0, 수평 : 1)
	bool operator<(const Node & arg) const {
		return this->c > arg.c;
	}
};

int solution(vector<vector<int>> board) {
    int answer = 0;

	int N = board.size();
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}; // 상하좌우

	vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(2, INF))); // i, j 위치에서 방향이 존재할 경우
	priority_queue<Node> q;

	dist[0][0] = {0, 0};
	dist[1][0][0] = dist[0][1][1] = 100;
	if(!board[1][0]) q.push({1, 0, 100, 0}); // (0, 0)에서 수직 이동
	if(!board[0][1]) q.push({0, 1, 100, 1}); // (0, 0)에서 수평 이동

	while(!q.empty()) {
		Node cur_node = q.top(); q.pop();
		int c_i = cur_node.i, c_j = cur_node.j;
		int c_c = cur_node.c, c_d = cur_node.dir;

		if(dist[c_i][c_j][c_d] < c_c) continue;

		for(int k=0; k<4; k++){
			int n_i = c_i + dx[k];
			int n_j = c_j + dy[k];
			int n_d = (c_j-n_j) == 0 ? 0 : 1; // 이동 전후 j가 같으면 수직 이동, 아니면 수평 이동
			int n_c = c_c + (c_d == n_d ? 100 : 600); 

			// 범위 초과 또는 벽
			if(n_i<0 || n_i>=N || n_j<0 || n_j>=N || board[n_i][n_j]==1) continue;
			
			// 이미 더 작은 경로를 찾은 경우 무시
			if(dist[n_i][n_j][n_d] < n_c) continue;

			dist[n_i][n_j][n_d] = n_c;
			q.push({n_i, n_j, n_c, n_d});
		}
	}

	answer = dist[N-1][N-1][0] <  dist[N-1][N-1][1] ?  dist[N-1][N-1][0] : dist[N-1][N-1][1];

    return answer;
}

int main(void) {
	showLine("start");
	// cout << solution({{0,0,0}, {0,0,0}, {0,0,0}}) <<"\n"; // 900
	// cout << solution({{0,1,0}, {0,0,0}, {0,1,0}}) <<"\n"; // 1400
	// cout << solution({
	// 	{0, 1, 0, 0, 0}, 
	// 	{0, 1, 0, 1, 0}, 
	// 	{0, 1, 0, 1, 0}, 
	// 	{0, 1, 0, 1, 0}, 
	// 	{0, 0, 0, 1, 0}
	// }) <<"\n"; // 3600
	// cout << solution({
	// 	{0, 0, 0, 0, 0}, 
	// 	{0, 1, 1, 1, 0}, 
	// 	{0, 1, 0, 1, 0}, 
	// 	{0, 1, 1, 1, 0}, 
	// 	{0, 0, 0, 0, 0}
	// }) <<"\n"; // 1300

	cout << solution({
		{0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0}
	}) <<"\n"; // 3000

	showLine("done");
	return 0;
}