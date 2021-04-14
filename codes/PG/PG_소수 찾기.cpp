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

#include "../infos.h"

using namespace std;

///////////////// 프로그래머스의 경우 전역 변수는 solution안에서 초기화 

int answer;
int checked[7];
set<int> num_list;

bool isPrime(int num) {
	if(num<=1) return false;

	for(int i=2; i*i<=num; i++){
		if(num % i == 0) return false;
	}
	return true;
}

void recursive(int idx, string & numbers, string & num) {
	if(idx==numbers.size()) return;
	for(int i=0; i<numbers.size(); i++){
		if(!checked[i]) {
			checked[i] = 1;
			num.push_back(numbers[i]);

			num_list.insert(stoi(num));
			recursive(idx+1, numbers, num);

			checked[i] = 0;
			num.pop_back();
		}

	}
}

int solution(string numbers) {
	answer=0;
	fill(checked, checked+7, 0);
	num_list = set<int>();

	string num = "";
	recursive(0, numbers, num);

	for(auto & e : num_list) {
		if(isPrime(e)) answer++;
	}


    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");
	// cout << solution("17")<<"\n";
	cout << solution("011")<<"\n";

	showLine("done");


	return 0;
}