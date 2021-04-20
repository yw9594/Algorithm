#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <string>
#include <cstring>
#include <sstream>   // ex) stringstream

#include <cmath>    
#include <cctype>    // ex) isdigit..

#include "../infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

int find(int node, vector<int> & tree) {
	if(tree[node]==node) return node;
	else return tree[node] = find(tree[node], tree);
}
bool check(int a, int b, vector<int> & tree) {
	int pa = find(a, tree); 
	int pb = find(b, tree); 

	if(pa!=pb) {
		tree[pb] = pa;
		return true;
	}
	else 
        return false;
}

bool pred(vector<int> & a, vector<int> & b) {return a[2] < b[2];}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

	vector<int> tree(n);
	for(int i=0; i<n; i++) tree[i] = i;

	sort(costs.begin(), costs.end(), pred);

	int cnt=0;
	for(auto & e : costs) {
		int a = e[0], b = e[1], cost=e[2];
		if(check(a, b, tree)) {
			answer += cost;
			if(++cnt==n-1) break;
		}
	}

    return answer;
}

int main(void) {
	showLine("start");
	// solution(4, {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}}); // 4
	// solution(4, {{1,0,1}, {2,0,2}, {2,1,5}, {3,1,1}, {3,2,8}}); // 4
	// solution(1, {}); // 4
	// solution(2, {{0, 1, 100}}); // 4
	solution(4, {{0, 1, 100}, {0, 3, 50}, {1,3,100}, {0, 2, 200}}); // 4
	showLine("done");
	return 0;
}