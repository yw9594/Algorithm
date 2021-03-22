///*
//	개요 : 백준 1926번 그림
//	요약 :
//		2차원 배열에서 1이 차지하는 영역의 개수와 최대 개수를 알아보자
//	방법 :
//		큐를 사용해 BFS를 구현한다.  
//	주의 사항:
//		push시 checked를 0에서 1로 바꾸어주어야 중복된 원소를 큐에 삽입하지 않는다. 
//*/
//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, M, cnt = 0, MX = 0;
//int offset[4][2]={
//	-1, 0,
//	1, 0, 
//	0, -1,
//	0, 1
//};
//inline pair<int, int> pos(int _i, int _j) { return pair<int, int>(_i, _j); }
//inline bool checkRange(int _i, int _j) {
//	if (_i < 0 || !(_i < N) || _j < 0 || !(_j < M)) return false;
//	return true;
//}
//
//int main(void) {
//	int arr[500][500] = {0}, checked[500][500] = { 0 };
//	queue<pair<int, int>> q;
//
//	std::ios::sync_with_stdio(false);
//
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
//	
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (!checked[i][j] && arr[i][j]) {
//				int temp_MX = 0;
//				cnt++;
//				q.push(pos(i, j));
//				checked[i][j] = 1;
//
//				while (!q.empty()) {
//					pair<int, int> cur_pos = q.front();
//					q.pop();
//
//					temp_MX++;
//					
//					for (int z = 0; z < 4; z++) {
//						int next_i = cur_pos.first + offset[z][0];
//						int next_j = cur_pos.second + offset[z][1];
//
//						if (checkRange(next_i, next_j) && !checked[next_i][next_j] && arr[next_i][next_j]) {
//							checked[next_i][next_j] = 1;
//							q.push(pos(next_i, next_j));
//						}
//					}
//				}
//				MX = temp_MX > MX ? temp_MX : MX;
//			}
//		}
//	}
//	
//	printf("%d\n%d\n", cnt, MX);
//
//
//
//	return 0;
//}