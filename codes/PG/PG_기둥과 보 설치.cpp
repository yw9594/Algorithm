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

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것
struct Pred{
	bool operator()(vector<int> & a, vector<int> & b){
		if(a[0]==b[0]) {
			if(a[1]==b[1]) return a[2]<b[2];
			return a[1]<b[1];
		}
		return a[0]<b[0];
	}
};
struct Elem{
	int c, r; // 기둥 보
	Elem(int _c=0, int _r=0):c(_c), r(_r){}
};
struct Board{
	int n;
	vector<vector<Elem>> board;
	Board(int _n) : n(_n) { 
		board = vector<vector<Elem>>(n+1, vector<Elem>(n+1));
	}
	void create(vector<int> & build){
		int c_i=build[0], c_j=build[1], type=build[2], op=build[3];
		bool flag= true;
		if(op==1) {	
			if(type==0) board[c_i][c_j].c = 1;
			else board[c_i][c_j].r = 1;
		}
		else{
			if(type==0) board[c_i][c_j].c = 0;
			else board[c_i][c_j].r = 0;
		}
		flag = check();
		if(!flag) {
			if(op==1) {	
				if(type==0) board[c_i][c_j].c = 0;
				else board[c_i][c_j].r = 0;
			}
			else{
				if(type==0) board[c_i][c_j].c = 1;
				else board[c_i][c_j].r = 1;
			}
		}
	}
	bool check(){
		bool ret = true;
		for(int i=0; i<=n&&ret; i++) {
			for(int j=1; j<=n&&ret; j++) {
				// 보 체크
				if(board[i][j].r) {
					if(board[i][j-1].c==1 || board[i+1][j-1].c==1 || (i!=0 && board[i-1][j].r==1 && board[i+1][j].r==1)) continue;
					else ret=false;
				}
				// 기둥 체크
				if(board[i][j].c) {
					if(board[i][j-1].c==1 || (i!=0 && board[i-1][j].r==1) || board[i][j].r==1) continue;
					else ret=false;
				}
			}
		}

		return ret;
	}
	vector<vector<int>> answer(){
		vector<vector<int>> ret;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				if(board[i][j].c) ret.push_back({i, j, 0});
				if(board[i][j].r) ret.push_back({i, j, 1});
			}
		}
		sort(ret.begin(), ret.end(), Pred());
		return ret;
	}
	
};

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
	Board board(n);
	for(auto & bf : build_frame) board.create(bf);
	answer = board.answer();

    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);
	
	showLine("start");

	//5	[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]	[[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]]
	// vector<vector<int>> answer = solution(5, {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}}); 
	vector<vector<int>> answer = solution(5, {{0,0,0,1}, {3,0,0,1}, {0,1,1,1}, {2,1,1,1}, {1,1,1,1}, {2,1,1,0} }); 
	show2dArray(answer);
	showLine("done");

	return 0;
}