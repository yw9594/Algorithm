#include <iostream>

#include <algorithm>
#include <vector>
#include <string>

#include "../infos.h"

using namespace std;

// 프로그래머스 문제 풀이 시 전역변수는 solution 변수 내에서 초기화한다.
using ll = long long int;

struct Info{
	int i;
	ll c, n;
	bool operator<(Info & arg){
		if(this->c * arg.n == this->n * arg.c) return this->i < arg.i;
		return this->c * arg.n > this->n * arg.c;
	}
};

vector<int> solution(int N, vector<int> stages) {
	int M = stages.size();
    vector<int> answer;

	vector<int> challenger(N+2, 0); // 1~N+2
	for(auto & s : stages) challenger[s]++;

	vector<int> num_of_challengers(N+2, 0);
	for(int i=N+1, cnt=0; i>-1; i--) num_of_challengers[i] = (cnt+=challenger[i]);

	vector<Info> ret;
	for(int i=1; i<=N; i++) ret.push_back({i, (ll)challenger[i], (ll)num_of_challengers[i]});

	sort(ret.begin(), ret.end());

	for(auto & i : ret) answer.push_back(i.i);

    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");	
	// solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
	solution(4, {4, 4, 4, 4, 4});
	// solution(4, {1, 2, 2});
	// solution(1, {2});
	showLine("done");	

	return 0;
}