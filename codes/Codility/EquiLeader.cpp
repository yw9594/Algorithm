#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<int, int> getCounter(set<int> & nums) {
    map<int, int> ret;
    for(auto & e : nums) ret.insert({e, 0});
    return ret;
}

int solution(vector<int> &A) {
    int answer=0;
    int N = A.size();

    if(N==1) return answer;

    set<int> nums; for(auto & e : A) nums.insert(e);

    int max_cnt, max_num;

    vector<int> left_leader(N);
    map<int, int> left_counter = getCounter(nums);

    for(int i=0, max_cnt = max_num = 0; i<N; i++) {
        auto it  = left_counter.find(A[i]);
        (it->second)++;

        int num = A[i], cnt = it->second;
        if(cnt > max_cnt) {
            max_cnt = cnt;
            max_num = num; 
        }

        int half = 1 + (i+1)/2;
        if(max_cnt >= half) left_leader[i] = max_num;
        else left_leader[i] = -1;
    }

    vector<int> right_leader(N);
    map<int, int> right_counter = getCounter(nums);

    for(int i=N-1, max_cnt = max_num = 0; i>-1; i--) {
        auto it  = right_counter.find(A[i]);
        (it->second)++;

        int num = A[i], cnt = it->second;
        if(cnt > max_cnt) {
            max_cnt = cnt;
            max_num = num; 
        }

        int half = 1 + (N-i)/2;
        if(max_cnt >= half) right_leader[i] = max_num;
        else right_leader[i] = -1;
    }
    
    for(int s=0; s<N-1; s++) {
        if(left_leader[s] == right_leader[s+1]) {
            if(left_leader[s]==-1) continue;
            answer++;
        }
    }
    return answer;
}