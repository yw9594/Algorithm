#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>   // ex) stringstream

#include "../infos.h"

using namespace std;

// 프로그래머스 문제 풀이 시 전역변수는 solution 변수 내에서 초기화한다.

vector<string> split(string & str){
	vector<string> toks;
	stringstream ss(str);
	string tok;
	while(getline(ss, tok, ' ')) toks.push_back(tok);
	return toks;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
	map<string, string> user; 


	// 최근 아이디 갱신
	for(auto & log : record) {
		vector<string> toks = split(log);
		if(!toks[0].compare("Leave")) continue;
		user[toks[1]] = toks[2];
	}

	// 로그 기록
	for(auto & log : record) {
		vector<string> toks = split(log);
		if(!toks[0].compare("Change")) continue; 
		else if (!toks[0].compare("Enter")) answer.push_back(user.find(toks[1])->second + "님이 들어왔습니다."); 
		else answer.push_back(user.find(toks[1])->second + "님이 나갔습니다."); 
	}

    return answer;
}

int main(void) {
	showLine("start");	
	show1dArray(solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"}));
	showLine("done");	

	return 0;
}