/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최소 힙
class MyHeap {
private:
	int size; // 원소 개수
	vector<int> data; // 데이터 저장 배열

public:
	MyHeap(int data_size) {
		this->size = 0;
		this->data = vector<int>(data_size + 1); // N개의 원소 저장. data[0] 사용 X
	}
public:
	void push(int x) {
		if (data.size() == size) return; // 공간 없음

		data[++size] = x; // 데이터 삽입

		int cur_node = size;
		int parent_node;
		while (cur_node != 1) { // 자식 노드가 부모 노드보다 작다면 교환
			parent_node = cur_node / 2;
			if (data[cur_node] < data[parent_node])
				swap(data[cur_node], data[parent_node]);
			cur_node = parent_node;
		}
		return;
	}
	void pop() {
		if (size == 0) return; // 원소 없음

		data[1] = data[size--]; // 마지막 원소를 root로 이동

		int cur_node = 1;
		int left_node, right_node, child_node;
		do {
			left_node = 2 * cur_node;
			right_node = 2 * cur_node + 1;

			if (left_node > size) break;													// 자식이 존재하지 않는 경우
			else if (left_node == size) child_node = left_node;								// 끝에서 왼쪽 자식만 존재하는 경우
			else child_node = data[left_node] < data[right_node] ? left_node : right_node;	// 양쪽 자식 모두 존재하는 경우

			if (data[child_node] < data[cur_node])
				swap(data[child_node], data[cur_node]);
			cur_node = child_node;
		} while (1);
	}
	int top() {
		return data[1];
	}

};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	MyHeap heap(N);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		heap.push(a);
	}

	for (int i = 0; i < N; i++) {
		cout << heap.top() << "\n";
		heap.pop();
	}


	return 0;
}*/