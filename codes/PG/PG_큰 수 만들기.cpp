/* ���α׷��ӽ� : ū ���� ��Ģ
    ���� ���ڿ��� k, len-k���� 2�� ���� a, b�� ������ b���� ��ü�� ���ڸ� a���� ���������� �����´�. 


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