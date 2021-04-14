#include <iostream>

#include <algorithm>
#include <set>

#include <string>
#include <sstream>   // ex) stringstream

#include "../infos.h"

using namespace std;

// 프로그래머스 문제 풀이 시 전역변수는 solution 변수 내에서 초기화한다.

vector<int> solution(vector<string> operations) {
	multiset<int> db;

	for(auto & oper : operations) {
		stringstream ss(oper);
		char op; int option;
		ss>>op>>option;

		if(op=='I') {
			db.insert(option);
		}
		else {
			if(!db.empty()) {
				if(option==-1) {
					db.erase(db.begin());
				}
				else{
					auto it = db.end();
					db.erase(--it);
				}
			}
		}
	}
	
    vector<int> answer(2, 0);
	if(db.size()!=0) {
		answer[0]=*db.rbegin();
		answer[1]=*db.begin();
	}

    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");	
	show1dArray(solution({"I 16","D 1"}));
	show1dArray(solution({"I 7","I 5","I -5","D -1"}));
	showLine("done");	

	return 0;
}