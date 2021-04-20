#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    vector<int> answer(N, 0);

    int base=0, max_val=0;
    for(int i=0; i<A.size(); i++) {
        int inst = A[i];
        if(inst>N) {
            base = max_val;
        }
        else{
            if(answer[inst-1]<=base) answer[inst-1]=base;

            answer[inst-1]++;
            max_val = answer[inst-1] > max_val ? answer[inst-1] : max_val;
        }
    }

    for(int i=0; i<N; i++) if(answer[i]<base) answer[i] = base;
    

    return answer;
}