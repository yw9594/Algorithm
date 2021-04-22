#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    int N = A.size();
    
    sort(A.begin(), A.end());

    int a = A[N-1] * A[N-2] * A[N-3];
    int b = A[N-1] * A[0] * A[1];

    return a > b ? a : b;
}
