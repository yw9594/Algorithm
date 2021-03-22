//#include <iostream>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//struct elem {
//	int i, j, h;
//	int cnt;
//	elem(int _h = -1, int _i = -1, int _j = -1, int _cnt = 0) :  h(_h), i(_i), j(_j), cnt(_cnt) {
//	}
//};
//
//const int MX = 100001;
//int offset[6][3] = { //  up, down, front, back, left, right
//	-1, 0, 0,
//	1,  0, 0,
//	0, -1, 0,
//	0,  1, 0,
//	0,  0, -1,
//	0,  0, 1
//};
//bool flag = true;
//int _front = 0, _rear = 0;
//int N, M, H, ans = 0, arr[100][100][100], pushed[100][100][100] = { 0 };
//elem q[MX];
//
//inline bool checkRange(int i, int j, int h) {
//	if (i >= 0 && j >= 0 && h >= 0 && i < N && j < M && h < H) return true;
//	return false;
//}
//
//int main(void) {
//	std::ios::sync_with_stdio(false);
//	
//	freopen("input.txt", "r", stdin);
//
//	fill(&arr[0][0][0], &arr[99][99][100], -1);
//
//	cin >> M >> N >> H;
//	for (int h = 0; h < H; h++) {
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < M; j++) {
//				cin >> arr[h][i][j];
//				if (arr[h][i][j] == 1) {
//					q[++_rear] = elem(h, i, j, 0);
//					pushed[h][i][j] = 1;
//				}
//			}
//		}
//	}
//
//	while (_rear - _front) {
//		elem cur_elem = q[++_front];
//
//		if (cur_elem.cnt > ans) ans = cur_elem.cnt;
//
//		for (int z = 0; z < 6; z++) {
//			int next_h = cur_elem.h + offset[z][0];
//			int next_i = cur_elem.i + offset[z][1];
//			int next_j = cur_elem.j + offset[z][2];
//
//			if (checkRange(next_i, next_j, next_h) &&
//				!pushed[next_h][next_i][next_j] &&
//				arr[next_h][next_i][next_j] == 0) {
//
//				arr[next_h][next_i][next_j] = 1;
//				q[++_rear] = elem(next_h, next_i, next_j, cur_elem.cnt + 1);
//				pushed[next_h][next_i][next_j] = 1;
//			}
//		}
//	}
//	// check not ripe tomatos.
//	for (int h = 0; h < H; h++) for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
//		if (arr[h][i][j] == 0)
//			flag = false;
//
//	if (!flag) ans = -1;
//	cout << ans << "\n";
//
//	return 0;
//}