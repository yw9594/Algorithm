/*
	���� : ���� 1406�� ������
	��� :
		Ŭ������ ����� LL�� �����غ���.
	���� :
		�� �ٸ� �ۼ��ϴ� �����͸� ������.
	������Ʈ :
		1. LL ������ root ��带 NULL�� �ۼ��ϸ� insert�� erase���� if���� ���� �������.
			��, �ݵ�� root node�� �������� �ȵȴ�.

		2. 1�� ������ erase�� insert �κп��� next node�� NULL�� ���ɼ��� ����ϸ�ȴ�.
			prev node�� root node�� ����� root�� ������ ���� �׻� NULL�� �� �� ����. 
			�ݴ�� ���ϸ� prev node�� NULL�̶�� �ݵ�� root node�̴�.
*/
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//struct Node {
//	char chr;
//	Node * prev, * next;
//public:
//	Node(char _chr=0, Node* _prev=NULL, Node* _next = NULL) :chr(_chr), prev(_prev), next(_next) {}
//};
//
//class Handler {
//	Node* pos_cursor;	// cursor position. cursor pointer mean, cursor is positioned right of that character.
//	Node* root;			// root ptr
//public:
//	Handler(char _initText[]) {
//
//		// 1. first node is root(null node)
//		root = new Node();
//
//		// 2. push characters.
//		int idx = 0;
//		Node* cur_node = root;
//		while (_initText[idx]) {
//			cur_node->next = new Node(_initText[idx], cur_node, NULL);
//			cur_node = cur_node->next;
//			idx++;
//		}
//		pos_cursor = cur_node;
//	};
//public:
//	void insert(char x) {
//		Node* left = pos_cursor;
//		Node* right = pos_cursor->next;
//		pos_cursor = new Node(x, left, right);
//		left->next = pos_cursor;
//		if(right!=NULL) right->prev = pos_cursor;
//	}
//	void erase() {
//		if (pos_cursor->prev == NULL) return;	// the first node(first posion) is ignored.
//		else {
//			Node* left = pos_cursor->prev;
//			Node* right = pos_cursor->next;
//
//			left->next = right;
//			if(right)right->prev = left;
//
//			delete pos_cursor;
//			pos_cursor = left;
//		}
//	}
//	void move(int dir) {
//		// positive: move right, negative: move left
//		if (dir) {
//			if(pos_cursor->next) // only right node of cursor is NOT NULL
//				pos_cursor = pos_cursor->next;
//		}
//		else {
//			if (pos_cursor->prev) // only left node of cursor is NOT NULL
//				pos_cursor = pos_cursor->prev;
//		}
//	}
//	void show() {
//		Node* cur_node = root;
//		
//		int idx=0;
//		char text[600001] = { 0 };
//		while (cur_node->next) {
//			cur_node = cur_node->next;
//			text[idx++] = cur_node->chr;
//		}
//
//		printf("%s\n", text);
//		
//		return;
//	}
//};
//
//int main(void) {
//	int t = 0,  N;
//	char initText[100002] = { 0 }, cmd[4] = {0};
//
//	scanf("%s %d\n", initText, &N);
//	
//	Handler LL(initText); // linked list ����
//
//	for(int t=0; t < N; t++){
//		cin.getline(cmd, 4);
//		switch (cmd[0]) {
//			case 'L': 
//				LL.move(0);
//				break;	
//			case 'D': 
//				LL.move(1);
//				break;	
//			case 'B': 
//				LL.erase();
//				break;	
//			case 'P':
//				LL.insert(cmd[2]);
//				break;
//		}
//	}
//	LL.show();
//
//	return 0;
//}