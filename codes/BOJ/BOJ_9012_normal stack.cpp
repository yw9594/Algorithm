///*
//	���� : ���� 9012�� ��ȣ
//	��� :
//		stack�� ����� �����غ���.
//	���� :
//		�� �ٸ� �ۼ��ϴ� �����͸� ������.
//	������Ʈ :
//*/
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//	std::ios::sync_with_stdio(false);
//	// cin.tie(0);
//	
//	int N;
//	cin >> N;
//	while (N--) {
//		int head = -1, flag=true;
//		string str;
//		cin >> str;
//
//		for (int i = 0; i < str.size() && true; i++) {
//			if (str[i] == '(') head++;
//			else if (head > -1) {
//				head--;
//			}
//			else flag = false;
//		}
//		if (head != -1) flag = false;
//
//
//		if (flag) printf("YES\n");
//		else printf("NO\n");
//	}
//	return 0;
//}