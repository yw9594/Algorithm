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

struct Range{
	int i, j;
	bool operator<(const Range & arg) const {
		if((this->j - this->i) == (arg.j - arg.i)) {
			if(this->i == arg.i) return this->j < arg.j;
			return this->i < arg.i;
		}
		return (this->j - this->i) < (arg.j - arg.i);
	}
};

vector<int> solution(vector<string> gems) {
	set<string> gem_types;

	for(auto & g : gems) gem_types.insert(g);
	int num_of_gem_types = gem_types.size();

	int N = gems.size();
	int left=0, right=0, cnt=0;

	vector<Range> answer_list;
	map<string, int> included;
	while(right != N) {
		// 새로운 보석 추가	
		auto it = included.find(gems[right]);
	
		if(it==included.end()) {
			included.insert({gems[right], 1});
			cnt++;
		}
		else (it->second)++;

		// 모든 보석 타입이 추가된 경우, left를 하나씩 삭제하면서 최솟값 탐색
		if(cnt==num_of_gem_types) {

			while(cnt==num_of_gem_types) {
				auto it = included.find(gems[left]);

				// left를 제거해도 모든 보석을 포함
				if(it->second > 1) {
					it->second--;
				} 
				// left를 제거하면 보석 타입이 하나 사라짐
				else{
					included.erase(it);
					cnt--;
					answer_list.push_back({left, right});
				}
				left++;
			}
		}		
		right++;
	}

	sort(answer_list.begin(), answer_list.end());

	// 인덱스 보정
	vector<int> answer = {answer_list[0].i+1, answer_list[0].j + 1};
    return answer;
}

int main(void) {
	showLine("start");
	
	show1dArray(solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"}));

	showLine("done");
	return 0;
}