///*
//	개요 : 백준 2493번 탑
//	요약 :
//		수직으로 세워진 여러 탑의 꼭대기에 송신기가 달려있다.
//		송신기들은 수평 왼쪽으로 레이저를 쏘는데 각 타워의 몸통은 레이저를 받을 수 있다.
//		각 타워의 레이저를 받는 타워의 번호를 구하자.
//
//	방법 :
//		스택을 사용해 현재 타워가 쏘는 레이저를 수신할 수 있는 타워를 빠르게 확인할 수 있다.(O(N))
//
//		레이저를 왼쪽으로 쏜다는 것은 어떤 타워 K가 존재할 때 K보다 작은 K의 왼쪽 타워들은 확인할 필요가 없다는 뜻이다.
//		
//		즉, 현재 타워의 높이에 따라 스택에는 레이저를 받을 수도 있는 타워의 번호들이 저장되어있다. 
//		이는 스택의 top을 확인해...
//			1) 스택의 top 타워보다 현재 타워의 높이가 낮다면 (stk.top().Height < cur_tower.Height) 
//				현재 타워의 높이보다 스택의 top의 타워보다 낮다는 의미므로 pop(stk.pop())한다. 
//				2)의 조건을 만족할 때까지 반복한다. 
//				
//			2) 해당 타워가 레이저를 받을 수 있다면 (stk.top().Height > cur_tower.Height) 
//				해당 타워의 번호를 정답으로 기록한다.
//		
//			3) 1), 2)를 마친 뒤엔 스택엔 현재 타워보다 높은 타워들만 저장되어있다. 
//				현재 타워가 수신 타워가 될 수 있으므로 스택에 저장한다. stk.push(cur_tower))
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