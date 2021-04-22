#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long int;

int solution(vector<int> &A) {
    ll answer=0;
    int N = A.size();

    vector<ll> low;
    vector<ll> high;

    for(ll i=0; i<N; i++) {
        low.push_back(i - (ll)A[i]);
        high.push_back(i + (ll)A[i]);
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    int idx=0; // last high;
    ll cnt=0; // number of disks where current disk is poped.
    for(ll & lo : low) {
        while(high[idx]< lo) {
            idx++;
            cnt--;
        }
        answer += cnt;
        if(answer>10000000) break;
        cnt++;
    }
    if(answer>10000000) answer=-1;

    return (int)answer;
}