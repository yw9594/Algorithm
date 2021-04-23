#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &H) {
    int answer=0;
    int N = H.size();

    vector<int> stk;

    stk.push_back(H[0]);
    answer++;

    for(int i=1; i<N; i++) {
        int top = stk.back(), h = H[i];

        if(top==h) continue;
        else if(top<h){
            stk.push_back(h);
            answer++;
        }
        else{
            while(!stk.empty() && stk.back() > h) stk.pop_back();
            if(!stk.empty() && stk.back()==h) continue;
            else {
                stk.push_back(h);
                answer++;
            }
        }
    }

    return answer;
}
