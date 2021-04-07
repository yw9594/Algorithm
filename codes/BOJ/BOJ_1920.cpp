#include <iostream>

#include <algorithm>
#include <vector>

#include "../infos.h"

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것
// 백준 사용 시 freopen, input.txt 사용할 것

int binarySearch(vector<int> & numbers, int k){
	int low=0, high=numbers.size()-1; //
	int mid;

	while(low<=high) {
		mid = (low+high)/2;
		if(numbers[mid]==k) return 1;
		else if(numbers[mid]<k) low = mid+1;
		else high=mid-1;
	}

	return 0;
}


int main(void) {
	int N, M;
	vector<int> numbers, search;

	cin>> N; numbers = vector<int>(N);
	for(int i=0; i<N; i++) cin>> numbers[i];

	cin>> M; search = vector<int>(M);
	for(int i=0; i<M; i++) cin>> search[i];

	sort(numbers.begin(), numbers.end());

	for(int i=0; i<M; i++) 
		cout << binarySearch(numbers, search[i])<<"\n";


	return 0;
}