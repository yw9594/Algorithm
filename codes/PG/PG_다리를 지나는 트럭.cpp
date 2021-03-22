/* 프로그래머스 : 다리를 지나는 트럭
    큐를 사용하면 간단히 해결할 수 있는 문제.

#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int len = truck_weights.size();
    int answer = 0;


    int i = 0, cap = 0; // i:다음 차량 인덱스, cap:현재 하중
    deque<pair<int, int>> dq; // f:무게, s:있었던 시간
    while (1) {
        answer++; // 시간 증가.

        int it_check = dq.size();
        while (it_check--) { // 먼저 들어온 차량부터 내보낸다.
            pair<int, int> first_car = dq.front();
            if (first_car.second == bridge_length) { // answer time에 다리 끝에 존재하는 차는 내보낸다.
                dq.pop_front();
                cap -= first_car.first;
            }
            else { // 아직 다리 위에 있는 차는 한 칸 이동시키고 다시 큐에 넣는다.
                dq.pop_front();
                dq.push_back(make_pair(first_car.first, first_car.second + 1));
            }
        }

        if (i == len && dq.empty()) break; // 대기줄과 다리에 차가 모두 없다면 끝낸다.

         // 차량이 남아있고 다리 길이와 무게가 된다면 추가 트럭을 다리 위로 올린다.
        if (dq.size() < bridge_length && i < len && (cap + truck_weights[i]) <= weight) {
            dq.push_back(make_pair(truck_weights[i], 1)); // 다리에 올라 서는 순간부터 1칸.
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