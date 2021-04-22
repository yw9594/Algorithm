#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int solution(vector<int> &A) {
    int N = A.size();

    vector<ll> arr;
    for(int i=0; i<N; i++) if(A[i]>0) arr.push_back(A[i]);

    if(arr.size()<3) return 0;

    sort(arr.begin(), arr.end(), greater<ll>());


    for(int i=0; i<arr.size()-2; i++) {
        if(arr[i+1] + arr[i+2] > arr[i]) return 1;
    }
    return 0;
}
