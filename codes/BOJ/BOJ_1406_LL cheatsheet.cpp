/*
	개요 : 백준 1406번 에디터
	요약 : 
		LL을 배열로 구현해본다.
	내용 :
		한 줄만 작성하는 에디터를 만들어본다.
	핀포인트 :
		1. LL 구조에 root 노드를 NULL로 작성하면 insert와 erase에서 if문이 많이 사라진다.
			단, 반드시 root node가 지워져선 안된다.

		2. 1의 이유로 erase와 insert 부분에서 next node가 NULL일 가능성만 고려하면된다.
			prev node는 root node의 존재로 root를 제외한 노드는 항상 NULL이 될 수 없다.
			반대로 말하면 prev node가 NULL이라면 반드시 root node이다.
*/

//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//const int MX = 600002;
//int pre[MX];
//int nex[MX];
//char dat[MX], cmd[4] = { 0 };
//
//const int root = 0;
//int cursor_pos;	// current cursor position.
//int empty_pos;	// empty space position
//
//using namespace std;
//
//void show() {
//	int cur_node = root, idx=0;
//	char text[600001] = { 0 };
//
//	while (nex[cur_node] != -1) {
//		cur_node = nex[cur_node];
//		text[idx++] = dat[cur_node];	
//	}
//	printf("%s\n", text);
//}
//void insert(char x) {
//	int left = cursor_pos, right = nex[cursor_pos];
//	
//	dat[empty_pos] = x;
//	pre[empty_pos] = left;
//	nex[empty_pos] = right;
//
//	nex[left] = empty_pos;
//	if (right != -1) pre[right] = empty_pos;
//
//	cursor_pos = empty_pos++;
//
//	return;
//}
//void erase() {
//	int left = pre[cursor_pos], right = nex[cursor_pos];
//
//	if (left == -1) return;
//
//	pre[cursor_pos] = nex[cursor_pos] = -1; // delete links
//	nex[left] = right;
//	if (right != -1) pre[right] = left;
//	cursor_pos = left;
//
//	return;
//}
//void move(int dir) {
//	if (!dir) { // left move
//		if (pre[cursor_pos] != -1)
//			cursor_pos = pre[cursor_pos];
//	}
//	else { // right move
//		if (nex[cursor_pos] != -1)
//			cursor_pos = nex[cursor_pos];
//	}
//}
//
//int main(void) {
//	int t = 0, len, N;
//	char initText[100002];
//
//	fill(pre, pre + MX, -1);
//	fill(nex, nex + MX, -1);
//
//	scanf("%s %d\n", initText, &N);
//	
//	// 1. 초기세팅
//	strcpy(dat + 1, initText);
//	len = strlen(initText);
//	for (int i = 0; i < len; i++) {
//		pre[i + 1] = i;
//		nex[i] = i + 1;
//	}
//	cursor_pos = len;
//	empty_pos = len + 1;
//
//	// 2. 명령어 처리
//	for(int t=0; t < N; t++){
//		cin.getline(cmd, 4);
//		switch (cmd[0]) {
//			case 'L': 
//				move(0);
//				break;	
//			case 'D': 
//				move(1);
//				break;	
//			case 'B': 
//				erase();
//				break;	
//			case 'P':
//				insert(cmd[2]);
//				break;
//		}
//	}
//
//	show();
//
//	return 0;
//}