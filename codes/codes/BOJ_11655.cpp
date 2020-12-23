/* BOJ_11655
ī�̻縣 ��ȣ�� ���, ���ڿ��� �о �� base ����('a', 'A')���� ��� ��ġ�� �����ϴ��� �˾ƾ� �Ѵ�. 
ex) 
4���� ���ĺ��� ������ ���� �ƽ�Ű �ڵ带 ������ 3ĭ�� �о�ٰ� �����Ѵ�.
	a:65(base) / b:66 / c:67 / d:68

���⼭ b�� 3ĭ �о ���, �ҹ����� ������ �����.
	b(66) -> 
	b_hat = b+3(69) -> 
	?(�� : a==65)

�켱 MOD �����ڸ� ����Ͽ� base ���ڸ� �������� base ���ڷκ��� �󸶳� �ָ� �������ִ°��� ���Ѵ�.
	pos = b_hat % base -> // �� ��� �ҹ��� 'a'�� base�̹Ƿ� 65�� �ش��Ѵ�.
	pos == 04

�� �� pos�� ������ ����(65~68)�� �Ѿ �� �����Ƿ� �� ������ ������ MOD ������ �����Ѵ�.
	pos %= 4 ->
	pos == 0

�̴� base ��ġ���� 0��ŭ ������ ��ġ�ǹ��ڷ� b�� ��ȯ�Ǿ��ٴ� ���̴�.
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
			int base = (int)(islower(cur_ch) ? 'a' : 'A'); // ��ҹ��� ����

			cur_ch = (char)cur_ch + 13;
			int pos = cur_ch % base;
			pos %= 26;

			str[i] = (char)(base + pos);
		}
	}
	cout << str;

	return 0;
}*/