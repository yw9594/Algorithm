#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include "../infos.h"

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(auto & s : scoville) pq.push(s);

	while(pq.size()>1 && pq.top()<K) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		cout << a<<" "<<b<<"\n";

		pq.push(a + 2*b);

		answer++;
	}
	if(pq.top()<K) answer=-1;

    return answer;
}

int main(void) {
	showLine("start");
	cout << solution({1, 2, 3, 9, 10, 12},7) <<"\n";
	showLine("done");

	return 0;
}