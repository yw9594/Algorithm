/* KMP 알고리즘 정리
	참고 사이트 : 
*/
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//  pi 테이블 만들기 
//	pi[i]: i번째 부분 문자열일때 prefix==surfix의 최대 길이 정리.
//	단, pi[i]=0 이며 prefix와 surfix가 겹치는 case 역시 허용한다.
//
//	문자가 매칭되지 않을 경우 j가 감소하는데, 이는 패턴 문자열 비교 기준이 뒤로 후퇴함을 의미한다.

vector<int> makeTable(string str) {
	int len = str.length();
	vector<int> table(len, 0); 

	// i:surfix index / j:prefix index
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j]) // prefix와 surfix의 단어가 다른 경우.
			j = table[j - 1];             // prefix index를 prefix==surfix일 때까지 후퇴시킴.
		if (str[i] == str[j])
			table[i] = ++j;
	}
	return table;
}

// kmp 알고리즘
//	1. 찾으려는 문자열을 p, 원본 문자열을 s라 한다.
//	2. 원본 문자열 s에서 p를 찾아나선다.
//	3. p를 찾던 도중 문자가 같지 않으면 pi table을 사용해 검사하지 않아도 될 부분을 스킵한다.

vector<int> kmp(string & s, string & p) {
	int n = s.size(), m = p.size();
	vector<int> pi = makeTable(p); // pi 테이블
	vector<int> ans; // p 문자열이 존재하는 부분의 인덱스.
	
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) 
			j = pi[j - 1];

		if (s[i] == p[j]) {
			if (j == m - 1) { // p 문자열을 찾은 경우
				ans.push_back(i-m+1); // p 문자열이 시작하는 부분의 인덱스 저장
				j = pi[j];			  // 불필요한 비교하지 않도록 jump
			}
			else j++;
		}
	}	
	return ans;
}


int main(void) {
	string s = "abcabc";
	string p = "abc";
	vector<int> ans = kmp(s, p);

	for (auto & a : ans)
		printf("%d ", a);

	return 0;
}*/