#include <iostream>
#include <algorithm>
#include <vector>

#define INF 99999999

using namespace std;

int binarySearch(int x, int arr[], int size){
	int ret=-1;
	int low=0, high=size, mid;

	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid]>x) { 
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	if(high==0) ret=-1;
	else ret = high;

	return ret;
}

int main(void) {
	int N; cin>>N;
	vector<int> arr(N);
	for(int i=0; i<N; i++) cin >> arr[i];

	int dp[1000]= {1,};
	int memo[1000] = {INF, arr[0]};
	int size=1;

	for(int i=1; i<N; i++){
		int k = binarySearch(arr[i], memo, size);
		if(k==-1) {
			dp[i]=1;
			if(arr[i] > memo[1]) memo[1] = arr[i];
		}
		else {
			dp[i] = 1 + k;
			if(arr[i] > memo[dp[i]]) memo[dp[i]] = arr[i];
			size++;
		}
	}
	cout << *max_element(dp, dp+1000)<<"\n";

	return 0;
}