/* ���α׷��ӽ� : ���� �� �縰���
    axx..xxb ������ ���ڿ����� a==b�̰� xx..xx�� �Ӹ�����̸� dp�� ����� Ǯ �� �ִ�.
*/
/*
#include <iostream>
#include <string>
using namespace std;
int ans = 0;
int checked[2500][2500] = { 0 };
void recursive(string& s, int first, int last) {
    int i = first, j = last;

    if (checked[i][j] == 1) return;   // �̹� �˻��� ��� �Ѿ��.
    else checked[i][j] = 1;          // ���� �˻����� ���� ��� üũ�Ѵ�. 

    while (s[i++] == s[j--] && i < j);

    if (i >= j) { // first~last ������ �縰����̴�.
        int len = (last - first + 1);
        ans = len > ans ? len : ans; // ���� ã�� �縰��Һ��� ��� �����Ѵ�.
    }
    else { // �縰����� �ƴϴ�.
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