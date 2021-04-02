#include <iostream>
#include <vector>
#include <set>

#include "../infos.h"

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
	set<long long> allocated_room, free_room;

	for(auto now : room_number) {
		// 이미 방이 배정된 경우
		if(allocated_room.find(now) != allocated_room.end()){
			// 현재 방 이후 배정할 수 있는 가장 작은 방을 선택한다.
			auto it = free_room.lower_bound(now);
			now = *it;
			free_room.erase(it);
		}
		// 방이 배정되지 않은 경우
		else {
			// 만약 빈 방 리스트에 다음 배정 방이 존재하는 경우 삭제한다.
			auto it = free_room.find(now);
			if(it != free_room.end()) free_room.erase(it);
		}
		
		// 방을 배정한다.
		allocated_room.insert(now);
		answer.push_back(now);

		// 현재 배정한 다음 방을 빈 방 리스트에 삽입한다. 만약 이미 배정되어있다면 추가하지 않는다. 
		if(allocated_room.find(now+1) == allocated_room.end()) free_room.insert(now+1);
	}

    return answer;
}

int main(void) {
	showLine("start");

	vector<long long> ret = solution(10, {1,3,4,1,3,1});
	show1dArray(ret);

	showLine("done");

	return 0;
}