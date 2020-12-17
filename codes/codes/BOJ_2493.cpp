///*
//	���� : ���� 2493�� ž
//	��� :
//		�������� ������ ���� ž�� ����⿡ �۽űⰡ �޷��ִ�.
//		�۽ű���� ���� �������� �������� ��µ� �� Ÿ���� ������ �������� ���� �� �ִ�.
//		�� Ÿ���� �������� �޴� Ÿ���� ��ȣ�� ������.
//
//	��� :
//		������ ����� ���� Ÿ���� ��� �������� ������ �� �ִ� Ÿ���� ������ Ȯ���� �� �ִ�.(O(N))
//
//		�������� �������� ��ٴ� ���� � Ÿ�� K�� ������ �� K���� ���� K�� ���� Ÿ������ Ȯ���� �ʿ䰡 ���ٴ� ���̴�.
//		
//		��, ���� Ÿ���� ���̿� ���� ���ÿ��� �������� ���� ���� �ִ� Ÿ���� ��ȣ���� ����Ǿ��ִ�. 
//		�̴� ������ top�� Ȯ����...
//			1) ������ top Ÿ������ ���� Ÿ���� ���̰� ���ٸ� (stk.top().Height < cur_tower.Height) 
//				���� Ÿ���� ���̺��� ������ top�� Ÿ������ ���ٴ� �ǹ̹Ƿ� pop(stk.pop())�Ѵ�. 
//				2)�� ������ ������ ������ �ݺ��Ѵ�. 
//				
//			2) �ش� Ÿ���� �������� ���� �� �ִٸ� (stk.top().Height > cur_tower.Height) 
//				�ش� Ÿ���� ��ȣ�� �������� ����Ѵ�.
//		
//			3) 1), 2)�� ��ģ �ڿ� ���ÿ� ���� Ÿ������ ���� Ÿ���鸸 ����Ǿ��ִ�. 
//				���� Ÿ���� ���� Ÿ���� �� �� �����Ƿ� ���ÿ� �����Ѵ�. stk.push(cur_tower))
//*/
//
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//const int MX = 500001;
//
//inline pair<int, long long int> tower(int idx, long long int H) { return pair<int, long long int>(idx, H); }
//
//int main(void) {
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int N;
//	int ans[MX] = {0};
//	long long int H;
//	stack<pair<int, long long int>> stk;	// (tower number, height)
//	
//	cin >> N;
//	cin >> H;
//	
//	stk.push(tower(1, H));
//
//	for (int i = 2; i <= N; i++) {
//		cin >> H;
//		pair<int, long long int> cur_tower = tower(i, H);
//
//		while (!stk.empty() && stk.top().second < cur_tower.second) stk.pop();
//
//		if (stk.empty()) ans[cur_tower.first] = 0;
//		else ans[cur_tower.first] = stk.top().first;
//
//		stk.push(cur_tower);
//	}
//
//	for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
//	printf("\n");
//
//
//	return 0;
//}