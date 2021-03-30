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
inline int min_val(int a, int b, int c){
	int t = a<b?a:b;
	return t<c?t:c;
} 
int solution(vector<vector<int>> board)
{
    int answer = 0, n=board.size(), m=board[0].size();
	vector<vector<int>> d(n, vector<int>(m, 0));

	for(int i=0; i<n; i++) if(board[i][0]) d[i][0] =1;
	for(int j=0; j<m; j++) if(board[0][j]) d[0][j] =1;
	
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
            if(board[i][j]) {
                d[i][j] = min_val(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1;
                if(d[i][j]*d[i][j]>answer) answer = d[i][j]*d[i][j];
            }
		}
	}
	if(n==1 && m==1) answer = board[0][0]; // 
	
	show2dArray(d);

    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");
	// cout << solution({{0,1,1,1}, {1,1,1,1},{1,1,1,1}, {0,0,1,0}})<<"\n";
	cout << solution({{1}})<<"\n";
	showLine("done");

	return 0;
}