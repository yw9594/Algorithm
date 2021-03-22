///*
//	���� : ���� 2178�� �̷� Ž��
//	��� :
//		2���� �迭���� �»�ܿ��� ���ϴ����� ���� �ִܰŸ��� ���غ���.
//	��� :
//		ť�� ����� BFS�� �����Ѵ�.  
//	������Ʈ :
//		BFS�� ������ ���ұ����� �ִܰŸ��� �����Ѵ�.
//	���� ����:
//		push�� checked�� 0���� 1�� �ٲپ��־�� �ߺ��� ���Ҹ� ť�� �������� �ʴ´�. 
//*/
//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//struct elem {
//	int i, j, path_len;
//	elem(int _i=-1, int _j=-1, int _path_len=-1) :i(_i), j(_j), path_len(_path_len) {}
//};
//
//int N, M, ans = 0;
//int offset[4][2]={
//	-1, 0,
//	1, 0, 
//	0, -1,
//	0, 1
//};
//inline bool checkRange(int _i, int _j) {
//	if (_i < 0 || !(_i < N) || _j < 0 || !(_j < M)) return false;
//	return true;
//}
//
//int main(void) {
//	char arr[100][100] = { 0 }, checked[100][100] = { 0 };
//	queue<elem> q;
//
//	scanf("%d %d", &N, &M);
//	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf(" %c", &arr[i][j]);
//
//
//	q.push(elem(0, 0, 1));
//	checked[0][0] = 1;
//
//	while (!q.empty()) {
//		elem cur_pos = q.front();
//		q.pop();
//		if (cur_pos.i == N - 1 &&  cur_pos.j == M - 1) {
//			ans = cur_pos.path_len;
//			break;
//		}
//
//		for (int z = 0; z < 4; z++) {
//			int next_i = cur_pos.i + offset[z][0];
//			int next_j = cur_pos.j + offset[z][1];
//
//			if (checkRange(next_i, next_j) && !checked[next_i][next_j] && arr[next_i][next_j]=='1') {
//				checked[next_i][next_j] = 1;
//				q.push(elem(next_i, next_j, cur_pos.path_len+1));
//			}
//		}
//	}
//
//
//	printf("%d\n", ans);
//
//	return 0;
//}