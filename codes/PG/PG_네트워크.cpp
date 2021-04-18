#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

	vector<int> pushed(n, 0);	

	for(int i=0; i<n; i++) {
		if(!pushed[i]){
			answer++;

			queue<int> q;

			q.push(i);
			pushed[i] =1;

			while(!q.empty()) {
				int cur_node = q.front(); q.pop();

				for(int next_node=0; next_node<n; next_node++) {
					if(computers[cur_node][next_node] && !pushed[next_node]) {
						q.push(next_node);
						pushed[next_node]=1;
					}
				}

			}
		}
	}

	cout << answer<<"\n";
	
    return answer;
}

int main(void) {
	showLine("start");
	solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
	showLine("done");
	return 0;
}