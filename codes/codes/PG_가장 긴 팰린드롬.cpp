/* 프로그래머스 : 가장 긴 펠린드롬
    axx..xxb 형태의 문자열에서 a==b이고 xx..xx가 팰린드롬이면 dp를 사용해 풀 수 있다.
*/
/*
#include <iostream>
#include <string>
using namespace std;
int ans = 0;
int checked[2500][2500] = { 0 };
void recursive(string& s, int first, int last) {
    int i = first, j = last;

    if (checked[i][j] == 1) return;   // 이미 검사한 경우 넘어간다.
    else checked[i][j] = 1;          // 아직 검사하지 않은 경우 체크한다. 

    while (s[i++] == s[j--] && i < j);

    if (i >= j) { // first~last 구간이 펠린드롬이다.
        int len = (last - first + 1);
        ans = len > ans ? len : ans; // 여태 찾은 펠린드롬보다 길면 저장한다.
    }
    else { // 펠린드롬이 아니다.
        recursive(s, first + 1, last);
        recursive(s, first, last - 1);
    }
}

int solution(string s)
{
    int answer = 0;
    int len = s.size();
    recursive(s, 0, len - 1);


    return ans;
}*/