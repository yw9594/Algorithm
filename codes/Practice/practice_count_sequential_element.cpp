#include <iostream>
#include <vector>

using namespace std;

// 1차원 배열 중 연속된 1 중 최대 개수를 반환한다. 
int countSequetial(vector<int> arr) {
	int cnt=0, i=0, n=arr.size(), ret=0;
	while(i<=n){
		if(i==n || arr[i]!=1) {
			ret = ret > cnt ? ret : cnt;
			cnt=0;
		}
		else cnt++;
		i++;
	}

	return ret;
}

int main(void) {

	vector<int> arr = {0, 1,1,0,1,1,1,1,1};
	cout << countSequetial(arr)<<"\n";

	return 0;
}