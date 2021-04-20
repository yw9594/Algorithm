#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <string>
#include <cstring>
#include <sstream>   // ex) stringstream

#include <cmath>    
#include <cctype>    // ex) isdigit..

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////
using ll = long long int;


long long solution(int n, vector<int> times) {
    long long answer = 0;
	ll low=1, high=1000000000000000000;
	ll mid;

	while(low<=high) {
		ll cnt=0;
		mid = (low + high)/2;

		for(int i=0; i<times.size(); i++) cnt += (mid / times[i]);

		if(cnt>=n) {
			answer = mid;
			high = mid-1;
		} 
		else low = mid+1;
	}

    return answer;
}

int main(void) {
	showLine("start");
	// solution(35, {99999999, 99999998, 99999997, 99999996, 99999995, 99999994, 99999993, 99999992, 99999991, 9999999});
	solution(6, {7, 10});

	showLine("done");
	return 0;
}