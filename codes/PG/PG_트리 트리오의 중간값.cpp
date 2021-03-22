/* 프로그래머스 : 트리 트리오의 중간값
     트리에서 임의의 한 점에서 가장 먼 점을 x, x 점에서 가장 먼 점을 y라하면 x-y는 트리의 서로 가장 먼 점이다.
     
     임의의 3개의 노드 a, b, c를 잡았을 때 중간값이 가장 크기 위해선 3개 노드 서로 멀리 떨어져 있어야 하므로
    x, y는 반드시 3개 노드 안에 들어간다.(a=x,b=y)
    
     이 때 남은 한 점 c는 x, y의 두번째로 가장 먼 노드 중 더 큰 중간 값을 갖기 위해 더 먼 거리를 가지는 노드를
     선택한다.

     참고 사이트 : https://blog.myungwoo.kr/112 
*/
/*
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

*/
/* BFS
    한 단말노드로부터 가장 가까운 단말 노드 vector로 반환.
    pair.first : 단말노드 번호.
    pair.second : snode로부터 거리.

vector<pair<int, int>> BFS(vector<vector<int>>& matrix, vector<int>& dnodes, int snode) {
    vector<pair<int, int>> ret; // 가장 가까운 노드부터 오름차순 정렬된다.

    deque<pair<int, int>> q; // bfs 큐 
    vector<bool> pushed(matrix.size(), false);

    q.push_back(pair<int, int>(snode, 0));
    pushed[snode] = true;

    while (!q.empty()) {
        pair<int, int> cur_elem = q.front();
        q.pop_front();

        int cur_node = cur_elem.first, cur_dist = cur_elem.second;

        if (matrix[cur_node].size() == 1 && cur_node != snode) ret.push_back(pair<int, int>(cur_node, cur_dist));

        for (auto& next_node : matrix[cur_node]) {
            if (!pushed[next_node]) {
                q.push_back(pair<int, int>(next_node, cur_dist + 1));
                pushed[next_node] = true;
            }
        }
    }

    return ret;
}
*/
/*
int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> matrix(n + 1); // 인접 리스트. maxtrix[0]은 사용하지 않는다.
    vector<int> dnodes; // 단말 노드

    for (auto& e : edges) { // 인접리스트 생성
        matrix[e[0]].push_back(e[1]);
        matrix[e[1]].push_back(e[0]);
    }

    for (int i = 1; i <= n; i++) // 단말 노드를 찾는다. 
        if (matrix[i].size() == 1)
            dnodes.push_back(i);

    // 임의의 한 단말노드로부터 가장 먼 점 하나를 구한다.
    vector<pair<int, int>> nodes = BFS(matrix, dnodes, dnodes[0]);
    int p1 = nodes[nodes.size() - 1].first;

    // 앞서 구한 한 점으로부터 가장 먼 점을 구한다. 이 두 점은 트리에서 가장 먼 노드이다.
    nodes = BFS(matrix, dnodes, p1);
    int p2 = nodes[nodes.size() - 1].first;

    if (nodes.size() != 1) { // 단말 노드가 3개 이상인 경우 p1, p2의 가장 먼 노드 중 두번째로 먼 노드의 길이 중 더 긴 것을 선택한다.
        answer = nodes[nodes.size() - 2].second;

        nodes = BFS(matrix, dnodes, p2);
        answer = answer > nodes[nodes.size() - 2].second ? answer : nodes[nodes.size() - 2].second;
    }
    else answer = nodes[nodes.size() - 1].second - 1; // 일자 형태인 경우 가장 긴 길이에서 -1 한 값이다.

    return answer;
}*/