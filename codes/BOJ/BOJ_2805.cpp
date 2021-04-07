#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것
// 백준 사용 시 freopen, input.txt 사용할 것

using ll = long long int;

ll check(vector<ll> & trees, int H) {
	ll ret=0;
	for(int i=0; i<trees.size(); i++) {
		if(trees[i]-H > 0) ret += (trees[i]-H);
	}
	return ret;
}
ll parametricSearch(vector<ll> & trees, int N, int M) {
	ll low = 0, high = *max_element(trees.begin(), trees.end());
	ll mid, ret;

	// mid만큼 잘라보고 가능하면 더 작게 자르고, 불가능하면 더 크게 잘라본다.
	while(low<=high) {
		mid = (low+high)/2;

		// mid만큼 잘랐을 때 가능하면 더 작게 잘라본다.
		if(check(trees, mid)>=M) {
			ret = mid;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return ret;
}

int main(void) {
	int N, M;
	vector<ll> trees;

	cin>> N >> M;
	trees = vector<ll>(N);
	for(int i=0; i<N; i++) cin >> trees[i];

	cout << parametricSearch(trees, N, M)<<"\n";

	return 0;
}