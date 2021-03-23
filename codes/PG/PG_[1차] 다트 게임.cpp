#include <iostream>

#include <vector>

#include <string>
#include <cstring>

#include <cctype>    // ex) isdigit..

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것.
struct elem{
	int s,b,o;
};

vector<elem> tokenize(string & log){
	int idx=0, n=log.size();
	int s, b,o;
	vector<elem> ret;
	while(idx<n){
		if(isdigit(log[idx])) {
			if(idx!=0 && isdigit(log[idx-1])) s = s * 10 + (log[idx]-'0');
			else s = (log[idx]-'0');
		}
		else if(strchr("SDT", log[idx])){
			if(log[idx]=='S') b=1;
			else if(log[idx]=='D') b=2;
			else b=3;
			
			if(idx+1<n && strchr("*#", log[idx+1])){
				idx++;
				o = (log[idx]=='*'? 2 : -1);
			}
			else o=1;
			ret.push_back({s, b, o});
		}
		idx++;
	}
	return ret;
}

inline int calcScore(elem & e) {
	int s = 1;
	for(int i=0; i<e.b; i++) s *= e.s;
	return s * e.o;
}

int solution(string dartResult) {
    int answer = 0;
	vector<elem> tokens = tokenize(dartResult);
	
	int old_score= calcScore(tokens[0]);

	for(int i=1; i<tokens.size(); i++){
		elem & cur_token = tokens[i];
		int cur_score = calcScore(cur_token);

		if(cur_token.o==2) old_score*=2;
		answer+= old_score;
		old_score = cur_score;
	}
	answer += old_score;

    return answer;
}

int main(void) {	
	cout << solution("1S2D*3T")<<"\n";
	cout << solution("1D2S#10S")<<"\n";
	cout << solution("1S*2T*3S")<<"\n";
	return 0;
}