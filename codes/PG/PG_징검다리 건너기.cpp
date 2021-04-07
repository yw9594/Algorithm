#include <iostream>

#include <algorithm>
#include <vector>

#include "../infos.h"

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것


// num보다 작은 돌들이 k번 이상 반복되어선 안된다.
bool check(vector<int> & stones, int num, int k) {
	int idx=0, cnt=0;
	while(idx<stones.size()) {
		if(stones[idx]<num) {
			cnt++;
			if(cnt>=k) return false;
		}
		else{
			cnt=0;
		}
		idx++;
	}
	return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

	int high = *max_element(stones.begin(), stones.end());
	int low = 1;
	int mid;

	// 가능한 사람 수를 이분 탐색을 통해 찾는다. 
	while(1){
		mid = (high + low) / 2;

		// mid가 가능하다면, 더 큰 값도 가능한지 확인한다.
		if(check(stones, mid, k)){
			answer = mid;
			low = mid+1;
		}
		// mid가 불가능하다면, 더 작은 값에서 가능한 값을 찾는다.
		else{
			high = mid-1;
		}
		if(low>high) break;
	}
	
	return answer;
}

int main(void) {
	showLine("start");

	cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) <<"\n";
	cout << solution({2}, 1) <<"\n";
	
	showLine("done");

	return 0;
}