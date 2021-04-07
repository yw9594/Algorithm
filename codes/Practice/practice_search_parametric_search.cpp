#include <iostream>
#include <algorithm>
#include <vector>
#include "../infos.h"

using namespace std;

int check(int K, int mid){
	if(K==mid) return 1;
	return 0;
}

int parametricSearch(int K) {
	int low=1, high=100;
	int mid, ret;

	while(low<=high) {
		mid = (low + high)/2;
		if(mid==K) {
			ret=mid;
			break;
		}
		if(K<mid) high =mid-1; // Down
		else low = mid+1;      // Up

	}
	return ret;
}

int main(void) {
	showLine("start");
	// 업 다운 게임 시작! A는 K를 생각하고 B는 K를 맞춘다. 
	// 단, 정답의 범위는 1~100이다.
	int K=2;
	if(K==parametricSearch(K)) 
		cout << "정답을 찾음!" <<"\n";

	showLine("done");

	return 0;
}