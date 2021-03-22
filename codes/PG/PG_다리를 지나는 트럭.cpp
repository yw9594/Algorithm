/* ���α׷��ӽ� : �ٸ��� ������ Ʈ��
    ť�� ����ϸ� ������ �ذ��� �� �ִ� ����.

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int len = truck_weights.size();
    int answer = 0;


    int i = 0, cap = 0; // i:���� ���� �ε���, cap:���� ����
    deque<pair<int, int>> dq; // f:����, s:�־��� �ð�
    while (1) {
        answer++; // �ð� ����.

        int it_check = dq.size();
        while (it_check--) { // ���� ���� �������� ��������.
            pair<int, int> first_car = dq.front();
            if (first_car.second == bridge_length) { // answer time�� �ٸ� ���� �����ϴ� ���� ��������.
                dq.pop_front();
                cap -= first_car.first;
            }
            else { // ���� �ٸ� ���� �ִ� ���� �� ĭ �̵���Ű�� �ٽ� ť�� �ִ´�.
                dq.pop_front();
                dq.push_back(make_pair(first_car.first, first_car.second + 1));
            }
        }

        if (i == len && dq.empty()) break; // ����ٰ� �ٸ��� ���� ��� ���ٸ� ������.

         // ������ �����ְ� �ٸ� ���̿� ���԰� �ȴٸ� �߰� Ʈ���� �ٸ� ���� �ø���.
        if (dq.size() < bridge_length && i < len && (cap + truck_weights[i]) <= weight) {
            dq.push_back(make_pair(truck_weights[i], 1)); // �ٸ��� �ö� ���� �������� 1ĭ.
            cap += truck_weights[i];
            i++;
        }
    }

    return answer;
}

int main(void) {
    vector<int> arr = {7,4,5,6};
    cout << solution(2, 10, arr) << endl;


    return 0;

}*/