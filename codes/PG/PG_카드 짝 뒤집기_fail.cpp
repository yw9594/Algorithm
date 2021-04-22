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

#include "infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////
struct Pos{
	int i, j;
};

// a -> b 최소 이동 비용
int move(int cur_card, Pos & a, Pos & b, vector<vector<int>> & board){
	int ai=a.i, aj=a.j, bi=b.i, bj=b.j;

	int cnt, si, sj;
	int row_offset = ai<bi ? 1 : -1, col_offset= aj<bj ? 1 : -1;
	int row_first=0, col_first=0;


	// 세로 이동 cost
	if(ai!=bi) {
		for(si=ai+row_offset, cnt=0; si!=bi ; si += row_offset) if(board[si][aj]) cnt++;
		row_first += (cnt+1);
		

		for(si=ai+row_offset, cnt=0; si!=bi ; si += row_offset) if(board[si][bj]) cnt++;
		col_first += (cnt+1);
	}

	// 가로 이동 -> 세로 이동
	if(aj!=bj){
		for(sj=aj+col_offset, cnt=0; sj!=bj ; sj += col_offset) if(board[ai][sj]) cnt++;
		row_first += (cnt+1);

		for(sj=aj+col_offset, cnt=0; sj!=bj ; sj += col_offset) if(board[bi][sj]) cnt++;
		col_first += (cnt+1);
	}

	return row_first < col_first ? row_first : col_first;
}

int min_path(int idx, Pos cur_pos, vector<int> & cards, vector<vector<Pos>> & position, vector<vector<int>> & board){
	if(idx==cards.size()) return 0;

	int cur_card = cards[idx]; 											// 현재 제거할 카드
	Pos pos1 = position[cur_card][0], pos2 = position[cur_card][1];		// 현재 제거할 카드의 위치

	// 첫 번째 카드를 제거하는 경우
	int cost1 = move(cur_card, cur_pos, pos1, board) + move(cur_card, pos1, pos2, board) + 2; // 2는 enter 횟수
	
	board[pos1.i][pos1.j] = board[pos2.i][pos2.j] = 0;
	cost1 += min_path(idx+1, pos2, cards, position, board);
	board[pos1.i][pos1.j] = board[pos2.i][pos2.j] = cur_card;

	// 두 번째 카드를 제거하는 경우
	int cost2 = move(cur_card, cur_pos, pos2, board) + move(cur_card, pos2, pos1, board) + 2; // 2는 enter 횟수
	board[pos1.i][pos1.j] = board[pos2.i][pos2.j] = 0;
	cost2 += min_path(idx+1, pos1, cards, position, board); 
	board[pos1.i][pos1.j] = board[pos2.i][pos2.j] = cur_card;

	return cost1 < cost2 ? cost1 : cost2; 
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 99999999;

	// 카드 종류
	set<int> card_type;
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) if(board[i][j]) card_type.insert(board[i][j]);

	// 카드 배열
	vector<int> cards;
	cards.assign(card_type.begin(), card_type.end());

	// 카드 위치
	vector<vector<Pos>> position(cards.size()+1, vector<Pos>());
	for(int i=0; i<4; i++) for(int j=0; j<4; j++) if(board[i][j]) position[board[i][j]].push_back({i, j});

	do{
		vector<vector<int>> new_board = board;
		int tmp = min_path(0, {r, c}, cards, position, new_board);
		if(answer==0 || tmp < answer) answer = tmp;
	} while(next_permutation(cards.begin(), cards.end()));

    return answer;
}

int main(void) {
	showLine("start");
	cout << solution({{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}}, 1, 0) <<"\n";
	cout << solution({{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}}, 0, 1) <<"\n";
	cout << solution({{1,0,0,2},{0,0,0,0},{0,0,0,0},{2,0,0,1}}, 0, 0) <<"\n";
	cout << solution({{1,1,2,2},{3,3,4,4},{5,5,6,6},{0,0,0,0}}, 0, 0) <<"\n";
	showLine("done");
	return 0;
}