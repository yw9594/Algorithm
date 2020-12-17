/* 프로그래머스 : 큰 수의 법칙
    숫자 문자열을 k, len-k개의 2개 구간 a, b로 나누고 b에서 교체될 숫자를 a에서 순차적으로 가져온다. 


#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k);
    for (int i = k - 1; i >= 0; i--)  
        int j = 0;
        do {
            if (number[i] >= answer[j]) {
                char temp = answer[j];
                answer[j] = number[i];
                number[i] = temp;
                j++;
            }
            else {
                break;
            }
        } while (1);
    }
    return answer;
}*/