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

using ll = long long;

vector<string> tokenize(string exp){
	vector<string> ret;
	string token = "";

	int idx=0;
	while(idx != exp.size()) {
		char ch = exp[idx];
		if(strchr("-+*", ch)) {
			ret.push_back(token);
			token = "";

			token += ch;
			ret.push_back(token);
			token="";
		}
		else{
			token += ch;
		}
		idx++;
	}
	ret.push_back(token);

	return ret;
}

map<string, int> getOpPriority(vector<string> ops){
	map<string, int> ret;
	for(int i=0; i<3; i++) {
		ret.insert({ops[i], i});
	}
	return ret;
}

string caclulate(string & a, string & b, string & op) {
	string ret;
	if(!op.compare("-")) {
		ret = to_string(stoll(a) - stoll(b));
	}
	else if(!op.compare("+")) {
		ret = to_string(stoll(a) + stoll(b));

	}
	else {
		ret = to_string(stoll(a) * stoll(b));
	} 
	return ret;
}

long long solution(string expression) {
    long long answer = 0;

	vector<string> tokens = tokenize(expression);

	vector<string> ops = {"-", "+", "*"};
	sort(ops.begin(), ops.end());

	do {
		map<string, int> opPriority = getOpPriority(ops);

		vector<string> expStk;
		vector<string> opStk;

		// 중위 표기식 -> 후위 표기식 변환
		for(string tok : tokens) {	
			if(!tok.compare("-") || !tok.compare("+") || !tok.compare("*")) {
				while(!opStk.empty() && opPriority[tok] >= opPriority[opStk.back()])  { // 연산자 우선순위가 같은 경우, 먼저 나온 연산자가 계산되어야 한다.
					expStk.push_back(opStk.back());
					opStk.pop_back();
				}
				opStk.push_back(tok);
			}
			else expStk.push_back(tok);
		}
		while(!opStk.empty()) {
			expStk.push_back(opStk.back());
			opStk.pop_back();
		}

		// 후위 표기식 계산
		vector<string> calcStk;
		for(string tok : expStk) {	
			if(!tok.compare("-") || !tok.compare("+") || !tok.compare("*")) {
				string op = tok;
				string b = calcStk.back(); calcStk.pop_back();
				string a = calcStk.back(); calcStk.pop_back();

				string c = caclulate(a, b, op); 
				calcStk.push_back(c);
			}
			else calcStk.push_back(tok);
		}

		ll tmp = abs(stoll(calcStk.back()));
		answer = answer > tmp ? answer : tmp;

	}while(next_permutation(ops.begin(), ops.end()));

    return answer;
}

int main(void) {
	showLine("start");

	cout << solution("100-200*300-500+20")<<"\n";

	showLine("done");
	return 0;
}