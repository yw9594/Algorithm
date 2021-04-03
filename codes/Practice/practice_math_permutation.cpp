#include <iostream>
#include <algorithm>
#include <vector>

#include "../infos.h"

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것

int main(void) {
	// next_permutation 주의 사항 
	// 1. operator< 가 반드시 정의되어있어야 한다.
	// 2. 반드시 처음엔 오름차순 정렬되어있어야 한다.
    
    vector<int> arr = {1,2,3,4};
	do{
		show1dArray(arr);
	}
	while(next_permutation(arr.begin(), arr.end())); 

	return 0;
}