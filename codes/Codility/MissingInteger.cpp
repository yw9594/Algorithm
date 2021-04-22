#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int answer;

    int N = A.size();
    vector<bool> checked(1000001, false);

    for(int i=0; i<N; i++) if(A[i]>0) checked[A[i]]=true;
    for(int i=1; i<=1000000; i++) {
        if(!checked[i]) {
            answer=i;
            break;
        }    
    }

    return answer;
}