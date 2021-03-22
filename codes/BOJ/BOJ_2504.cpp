///*
//	���� : ���� 2504�� ��ȣ�� ��
//	��� :
//		(, ), [, ] �� �����ϴ� ������ ���� ����Ѵ�.
//	��� :
//		�ٽ� ������ ������ ����.
//		1. '(', '[' ��ȣ :
//			���ÿ� ��ȣ�� �߰��ϰ� ������ 2 �Ǵ� 3�� ���� ���� ������ ���Ŀ� ���ؾߵ� ��(mutiplier)�� ����Ѵ�.
//
//		2. ')', ']' ��ȣ :
//			1) �� ���ڰ� '(', '['�� ��� :
//				"()", "[]"�� �ش��ϹǷ� multimplier�� result�� ���Ѵ�. �ϳ��� ��ȣ�� �ϼ��Ǿ����Ƿ� mutiplier�� ���� ��ȣ�� �ش��ϴ� ������ �����ְ� stk�� pop�Ѵ�.
//			2) �� ���ڰ� ')', ']'�� ���
//				")]", "))". "])", "]]" �� �ش��Ѵ�. �ϳ��� ��ȣ�� �ϼ��Ǿ����Ƿ� mutiplier�� ���� ��ȣ�� �ش��ϴ� ������ �����ְ� stk�� pop�Ѵ�.
//
//		�̸� �� �� ���ϰ� �����Ϸ��� (, ), [, ]�� �̷���� ������ ���ڽ����� ǥ���� �� Ǯ����ġ�� �ȴ�.
//		ex)
//			[(()[()])]() = 3x2x2x(2 + 3 x (2)) + 2
//						 = 3x2x2x2 + 3x2x2x3x2 + 2
//
//			���� �� ���캸�� (), []�� ���� ���� ��(multiplier)�� result�� ���ϴ� ���� �� �� �ִ�.
//	���� ����:
//		��ȣ�� �׻� ��Ȯ�� ���� �̷� ��ȯ�ȴٴ� ������ �����Ƿ� �� ��Ȳ�� ���� ���� ó���� ���־���Ѵ�.
//		1) ù ���ڰ� ')', ']'�� ���
//		2) ������ ����µ� ')', ']'�� ������ ���
//		3) ����� ���ƴµ� ���ÿ� ��ȣ�� �����ִ� ���
//*/
//
//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//	long long int val[200];
//	long long int res = 0LL, multiplier = 1LL;
//	string str;
//	stack<int> stk;
//
//	std::ios::sync_with_stdio(false);
//	val['('] = val[')'] = 2LL;
//	val['['] = val[']'] = 3LL;
//
//	cin >> str;
//	for (int i = 0; i < str.size(); i++) {
//		char cur_ch = str[i];
//		if (cur_ch == '(' || cur_ch == '[') {
//			stk.push(val[cur_ch]);
//			multiplier *= val[cur_ch];
//		}
//		else {
//			if (i == 0 || stk.empty() || stk.top() != val[cur_ch]) { res = 0LL; break; }
//
//			char old_ch = str[i - 1];
//
//			if (old_ch == '(' || old_ch == '[')  // (), []�� ��� 
//				res += multiplier;
//			multiplier /= stk.top();
//			stk.pop();
//		}
//	}
//	if (!stk.empty()) res = 0LL;
//
//	printf("%lld\n", res);
//
//
//	return 0;
//}