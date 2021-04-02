#include <iostream>

#include <algorithm>
#include <vector>
#include <set>

#include <string>
#include <sstream>   // ex) stringstream

#include "../infos.h"

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것
using namespace std;

struct Pred{
	bool operator()(set<int> & a, set<int> & b){
		return a.size()<b.size();
	}
};
vector<string> split(string& str, char delim = ' ') {
	vector<string> toks;
	stringstream ss(str);
	string tok;

	while (getline(ss, tok, delim)) toks.push_back(tok);

	return toks;
}

vector<set<int>> parsing(string & s) {
	vector<set<int>> ret;
	string str = s.substr(1, s.size()-2);

	int i=0, j=0;
	while(i<str.size()) {
		if(str[i]=='{') {
			i++;
			j=i;
			while(str[j]!='}') j++;
			string tmp = str.substr(i, j-i);
			vector<string> toks = split(tmp, ',');
			set<int> subset;
			for(auto & t : toks) subset.insert(stoi(t));
			ret.push_back(subset);
			i=j;
		}
		else i++;
	}

	return ret;
}

vector<int> solution(string s) {
    vector<int> answer;

	vector<set<int>> sets = parsing(s);
	sort(sets.begin(), sets.end(), Pred());	

	int checked[100001] = {0, };
	for(set<int> & subset : sets){
		for(auto & e : subset) {
			if(!checked[e]) {
				answer.push_back(e);
				checked[e]=1;
			}
		}
	}

    return answer;
}

int main(void) {
	showLine("start");
	show1dArray(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"));
	showLine("done");

	return 0;
}