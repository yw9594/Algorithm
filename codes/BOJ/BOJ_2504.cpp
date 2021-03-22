///*
//	개요 : 백준 2504번 괄호의 값
//	요약 :
//		(, ), [, ] 가 구성하는 수식의 값을 계산한다.
//	방법 :
//		핵심 내용은 다음과 같다.
//		1. '(', '[' 괄호 :
//			스택에 괄호를 추가하고 변수에 2 또는 3을 곱해 가장 안쪽의 수식에 곱해야될 수(mutiplier)를 계산한다.
//
//		2. ')', ']' 괄호 :
//			1) 앞 문자가 '(', '['일 경우 :
//				"()", "[]"에 해당하므로 multimplier를 result에 더한다. 하나의 괄호가 완성되었으므로 mutiplier를 현재 괄호에 해당하는 값으로 나눠주고 stk을 pop한다.
//			2) 앞 문자가 ')', ']'일 경우
//				")]", "))". "])", "]]" 에 해당한다. 하나의 괄호가 완성되었으므로 mutiplier를 현재 괄호에 해당하는 값으로 나눠주고 stk을 pop한다.
//
//		이를 좀 더 편하게 이해하려면 (, ), [, ]로 이루어진 수식을 숫자식으로 표현한 뒤 풀어해치면 된다.
//		ex)
//			[(()[()])]() = 3x2x2x(2 + 3 x (2)) + 2
//						 = 3x2x2x2 + 3x2x2x3x2 + 2
//
//			식을 잘 살펴보면 (), []일 때만 식의 값(multiplier)를 result에 더하는 것을 볼 수 있다.
//	주의 사항:
//		괄호가 항상 정확한 쌍을 이뤄 반환된다는 보장이 없으므로 각 상황에 대해 예외 처리를 해주어야한다.
//		1) 첫 문자가 ')', ']'인 경우
//		2) 스택이 비었는데 ')', ']'가 나오는 경우
//		3) 계산을 마쳤는데 스택에 괄호가 남아있는 경우
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
//			if (old_ch == '(' || old_ch == '[')  // (), []일 경우 
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