/* BOJ_11655
카이사르 암호의 경우, 문자열을 밀어낼 때 base 문자('a', 'A')부터 어느 위치에 존재하는지 알아야 한다. 
ex) 
4개의 알파벳이 다음과 같은 아스키 코드를 가지고 3칸씩 밀어낸다고 가정한다.
	a:65(base) / b:66 / c:67 / d:68

여기서 b를 3칸 밀어낼 경우, 소문자의 범위를 벗어난다.
	b(66) -> 
	b_hat = b+3(69) -> 
	?(답 : a==65)

우선 MOD 연산자를 사용하여 base 문자를 기준으로 base 문자로부터 얼마나 멀리 떨어져있는가를 구한다.
	pos = b_hat % base -> // 이 경우 소문자 'a'가 base이므로 65에 해당한다.
	pos == 04

이 때 pos가 문자의 범위(65~68)을 넘어설 수 있으므로 총 문자의 개수로 MOD 연산을 수행한다.
	pos %= 4 ->
	pos == 0

이는 base 위치에서 0만큼 떨어진 위치의문자로 b가 변환되었다는 뜻이다.
	b_hat = base + pos
	b_hat == 65


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void) {
	string str;
	string answer;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, str, '\n');
	int len = str.length();
	for (int i = 0; i < len; i++) {
		int cur_ch = (int)str[i];
		if (isalpha(cur_ch)) {
			int base = (int)(islower(cur_ch) ? 'a' : 'A'); // 대소문자 구분

			cur_ch = (char)cur_ch + 13;
			int pos = cur_ch % base;
			pos %= 26;

			str[i] = (char)(base + pos);
		}
	}
	cout << str;

	return 0;
}*/