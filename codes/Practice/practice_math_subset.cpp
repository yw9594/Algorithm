#include <iostream>
#include <vector>
#include <set>

#include <string>

#include "../infos.h"

using namespace std;

// arr 집합의 모든 부분 집합을 구하는 함수
void subset(vector<int> & arr, vector<int> & elem, vector<vector<int>> & ret, int idx=0){
	if(idx == arr.size()) {
		ret.push_back(elem);
		return;
	}

	// 포함하는 경우
	elem.push_back(arr[idx]);
	subset(arr, elem, ret, idx+1);
	elem.pop_back();

	// 포함하지 않는 경우
	subset(arr, elem, ret, idx+1);
}

int main(void) {
	vector<int> arr = {1,2,3};			// 집합
	vector<int> temp;					// 부분 집합을 임시 저장하기 위한 객체(함수 전달용)
	vector<vector<int>> all_subset;     // 부분집합

	subset(arr, temp, all_subset);

	show2dArray(all_subset);
	
	return 0;
}