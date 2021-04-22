#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#include "../infos.h"

using namespace std;

// 프로그래머스 문제 풀이 시 전역변수는 solution 변수 내에서 초기화한다.

struct Task{
	int a, n;	// 도착 시간, 걸리는 시간
	bool operator<(const Task & arg) const{
		if(this->a == arg.a) return this->n < arg.n;
		return this->a < arg.a;
	}
};
struct Pred{
	bool operator()(Task & a, Task & b) { return a.n > b.n;}
};

int solution(vector<vector<int>> jobs) {
   	int answer=0;
	vector<Task> tasks;

	for(int i=0; i<jobs.size(); i++) tasks.push_back({jobs[i][0], jobs[i][1]});
	sort(tasks.begin(), tasks.end());

	int idx=0, now=0, N =jobs.size();
	priority_queue<Task, vector<Task>, Pred> pq;

	idx++; pq.push(tasks[0]);
	while(!pq.empty()) {
		Task cur_task = pq.top(); pq.pop();

		// waiting에서 가져오는 경우, 도착시간을 고려한다.
		if(cur_task.a < now)  {
			now += cur_task.n;
			answer += now - cur_task.a;
		}	
		// idle한 경우, 바로 시작한다.
		else{
			now = cur_task.a + cur_task.n;
			answer += cur_task.n;
		}

		// 작업이 더 없으면 추가하지 않음
		if(idx==N) continue;

		// now 이전에 도착한 작업(waiting)은 모두 넣어 준다.
		if(tasks[idx].a < now) {
			while(idx != N && tasks[idx].a < now) pq.push(tasks[idx++]);
		}
		// 만약 pq에 아직 작업이 남아 있을 경우, 수행한다.
		else if(!pq.empty()) continue;
		// idle한 경우 이후 가장 먼저 도착한 작업을 넣는다. 
		else pq.push(tasks[idx++]);
	}

	return answer / tasks.size();
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);

	showLine("start");	
	// cout << solution({{0, 3}, {1, 9}, {2, 6}})<<"\n";
	// cout << solution({{0, 3}, {0, 3}, {0, 3}})<<"\n";
	// cout << solution({{0, 3}, {1, 5}})<<"\n";
	// cout << solution({{0, 3}, {4, 5}})<<"\n";
	// cout << solution({{0, 1}, {1, 1}, {2, 1}, {3, 1}})<<"\n";
	// cout << solution({{0, 10}, {2, 10}, {9, 10}, {15, 2}})<<"\n";
	// cout << solution({{0, 9}, {1, 1}, {1, 1}})<<"\n";
	cout << solution({{0, 1}}) << "\n";
	// cout << solution({{0, 3}, {1, 7}, {1, 5}, {1, 6}})<<"\n";

	showLine("done");	

	return 0;
}