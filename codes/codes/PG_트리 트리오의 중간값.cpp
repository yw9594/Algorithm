/* ���α׷��ӽ� : Ʈ�� Ʈ������ �߰���
     Ʈ������ ������ �� ������ ���� �� ���� x, x ������ ���� �� ���� y���ϸ� x-y�� Ʈ���� ���� ���� �� ���̴�.
     
     ������ 3���� ��� a, b, c�� ����� �� �߰����� ���� ũ�� ���ؼ� 3�� ��� ���� �ָ� ������ �־�� �ϹǷ�
    x, y�� �ݵ�� 3�� ��� �ȿ� ����.(a=x,b=y)
    
     �� �� ���� �� �� c�� x, y�� �ι�°�� ���� �� ��� �� �� ū �߰� ���� ���� ���� �� �� �Ÿ��� ������ ��带
     �����Ѵ�.

     ���� ����Ʈ : https://blog.myungwoo.kr/112 
*/
/*
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

*/
/* BFS
    �� �ܸ����κ��� ���� ����� �ܸ� ��� vector�� ��ȯ.
    pair.first : �ܸ���� ��ȣ.
    pair.second : snode�κ��� �Ÿ�.

vector<pair<int, int>> BFS(vector<vector<int>>& matrix, vector<int>& dnodes, int snode) {
    vector<pair<int, int>> ret; // ���� ����� ������ �������� ���ĵȴ�.

    deque<pair<int, int>> q; // bfs ť 
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
    vector<vector<int>> matrix(n + 1); // ���� ����Ʈ. maxtrix[0]�� ������� �ʴ´�.
    vector<int> dnodes; // �ܸ� ���

    for (auto& e : edges) { // ��������Ʈ ����
        matrix[e[0]].push_back(e[1]);
        matrix[e[1]].push_back(e[0]);
    }

    for (int i = 1; i <= n; i++) // �ܸ� ��带 ã�´�. 
        if (matrix[i].size() == 1)
            dnodes.push_back(i);

    // ������ �� �ܸ����κ��� ���� �� �� �ϳ��� ���Ѵ�.
    vector<pair<int, int>> nodes = BFS(matrix, dnodes, dnodes[0]);
    int p1 = nodes[nodes.size() - 1].first;

    // �ռ� ���� �� �����κ��� ���� �� ���� ���Ѵ�. �� �� ���� Ʈ������ ���� �� ����̴�.
    nodes = BFS(matrix, dnodes, p1);
    int p2 = nodes[nodes.size() - 1].first;

    if (nodes.size() != 1) { // �ܸ� ��尡 3�� �̻��� ��� p1, p2�� ���� �� ��� �� �ι�°�� �� ����� ���� �� �� �� ���� �����Ѵ�.
        answer = nodes[nodes.size() - 2].second;

        nodes = BFS(matrix, dnodes, p2);
        answer = answer > nodes[nodes.size() - 2].second ? answer : nodes[nodes.size() - 2].second;
    }
    else answer = nodes[nodes.size() - 1].second - 1; // ���� ������ ��� ���� �� ���̿��� -1 �� ���̴�.

    return answer;
}*/