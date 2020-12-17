/* ���α׷��ӽ� : ǳ�� ��Ʈ����
    �迭 ���� ���Ҵ� �׻� �����ϸ�, ������ �ƴ� ���� a[i]�� a[0]~a[i-1] �� �ּ�, a[i+1]~a[len-1] �� 
    �ּҺ��� ũ�� ���� �Ұ����ϴ�.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0, len = a.size();
    vector<int> min_left(len), min_right(len); // min_left[i]: �������κ��� i���� ���� �� �ּڰ�. min_right[i]: ���������κ��� i���� ���� �� �ּڰ�.

    min_left[0] = a[0];         // ù ���Ҵ� �׻� �ּڰ��̴�. 
    min_right[len - 1] = a[len - 1];

    int min_g = min_left[0];
    for (int i = 1; i < len; i++) {
        min_left[i] = min_g = a[i] < min_g ? a[i] : min_g; // min_left�� ���� ���� ����.     
    }
    min_g = min_right[len - 1];
    for (int i = len - 2; i > -1; i--)
        min_right[i] = min_g = a[i] < min_g ? a[i] : min_g; // min_right ���� ���� ����.     

    if (len < 3) return len; // 2 ������ ���̴� �׻� ��� �����ϴ�.
    answer += 2;
    for (int i = 1; i < len - 1; i++) {
        if (a[i] > min_left[i - 1] && a[i] > min_right[i + 1]) continue;
        else answer++;
    }


    return answer;
}*/

/* �ٸ� Ǯ�� : 
    a[i] < a[k] < a[j], i+1<=k<=j-1�� ��� a[k]�� �Ұ����ϴٴ� ������ ������ ����� ���� �ִ�.

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