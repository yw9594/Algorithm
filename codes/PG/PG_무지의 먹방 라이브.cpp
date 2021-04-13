#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>


#include "../infos.h"

using namespace std;

// 프로그래머스 문제 풀이 시 전역변수는 solution 변수 내에서 초기화한다.

using ll = long long int;

struct Food{
	int i, n;
	bool operator<(const Food & arg) const {
		return this->n > arg.n;
	}
};
bool pred(Food & a, Food & b){return a.i<b.i;}

int solution(vector<int> food_times, long long k) {
	ll up_time = 0LL;
	priority_queue<Food> pq;

	for(int i=0; i<food_times.size(); i++) {
		pq.push({i+1, food_times[i]});
		up_time += food_times[i];
	}
	if(up_time <= k) return -1;

	int M = food_times.size(); 
	Food old_food = {0, 0};
	up_time=0LL;

	while(1) {
		Food cur_food = pq.top(); pq.pop();

		up_time += (ll)(cur_food.n - old_food.n) * M;

		if(up_time>k) {
			pq.push(cur_food);
			up_time -= (ll)(cur_food.n - old_food.n) * M;
			break;
		}

		M--;
		old_food=cur_food;
	}
	
	vector<Food> ret;
	while(!pq.empty()) {
		ret.push_back(pq.top()); pq.pop();
	}
	sort(ret.begin(), ret.end(), pred);

    return ret[(k-up_time)%M].i;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");	

	// cout << solution({1, 1, 1, 2, 2, 4, 4, 4, 5, 5}, 500) <<"\n";
	// cout << solution({3, 1, 2}, 4) <<"\n";
	// cout << solution({3, 1, 2}, 5) <<"\n";
	// cout << solution({4, 4, 4}, 5) <<"\n";
	// solution({1}, 5);


	showLine("done");	

	return 0;
}