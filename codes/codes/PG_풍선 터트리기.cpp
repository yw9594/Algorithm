/* 프로그래머스 : 풍선 터트리기
    배열 양쪽 원소는 항상 가능하며, 양쪽이 아닌 원소 a[i]는 a[0]~a[i-1] 중 최소, a[i+1]~a[len-1] 중 
    최소보다 크면 답이 불가능하다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0, len = a.size();
    vector<int> min_left(len), min_right(len); // min_left[i]: 왼쪽으로부터 i까지 원소 중 최솟값. min_right[i]: 오른쪽으로부터 i까지 원소 중 최솟값.

    min_left[0] = a[0];         // 첫 원소는 항상 최솟값이다. 
    min_right[len - 1] = a[len - 1];

    int min_g = min_left[0];
    for (int i = 1; i < len; i++) {
        min_left[i] = min_g = a[i] < min_g ? a[i] : min_g; // min_left에 작은 값을 유지.     
    }
    min_g = min_right[len - 1];
    for (int i = len - 2; i > -1; i--)
        min_right[i] = min_g = a[i] < min_g ? a[i] : min_g; // min_right 작은 값을 유지.     

    if (len < 3) return len; // 2 이하의 길이는 항상 모두 가능하다.
    answer += 2;
    for (int i = 1; i < len - 1; i++) {
        if (a[i] > min_left[i - 1] && a[i] > min_right[i + 1]) continue;
        else answer++;
    }


    return answer;
}*/

/* 다른 풀이 : 
    a[i] < a[k] < a[j], i+1<=k<=j-1인 모든 a[k]는 불가능하다는 점에서 스택을 사용할 수도 있다.

#include <string>
#include <vector>
#include <stack>

using namespace std;
int solution(vector<int> a) {
    int answer = a.size();
    stack<int> stack;
    for(int comp : a){
        while(!stack.empty() && comp < stack.top()){
            stack.pop();
            if(!stack.empty())
                answer--;
        }
        stack.push(comp);
    }
    return answer;
}

*/