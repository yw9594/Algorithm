/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyHeap {
private:
	int size; 
	vector<int> data;

public:
	MyHeap(int data_size) {
		this->size = 0;
		this->data = vector<int>(data_size + 1); 
	}
public:
	void push(int x) {
		if (data.size() == size) return;

		data[++size] = x;

		int cur_node = size;
		int parent_node;
		while (cur_node != 1) { 
			parent_node = cur_node / 2;
			if (data[cur_node] < data[parent_node])
				swap(data[cur_node], data[parent_node]);
			cur_node = parent_node;
		}
		return;
	}
	void pop() {
		if (size == 0) return; 

		data[1] = data[size--];

		int cur_node = 1;
		int left_node, right_node, child_node;
		do {
			left_node = 2 * cur_node;
			right_node = 2 * cur_node + 1;

			if (left_node > size) break;													
			else if (left_node == size) child_node = left_node;								
			else child_node = data[left_node] < data[right_node] ? left_node : right_node;

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