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

#include "infos.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

#define INF 99999999

struct Edge{
	int dest;
	int cost;
};

struct Move{
	int node;
	int dist;
	bool operator<(const Move & arg) const { return this->dist > arg.dist;}
};

vector<int> dijkstra(int N, int start, vector<vector<Edge>> & mat) {
	vector<int> dist(N+1, INF);
	priority_queue<Move> pq;

	pq.push({start, 0});
	dist[start] = 0;

	while(!pq.empty()) {
		int cur_node = pq.top().node;
		int cur_dist = pq.top().dist;
		pq.pop();

		if(dist[cur_node] < cur_dist) continue;

		// dist[cur_node] = cur_dist;

		for(Edge & e : mat[cur_node]) {
			int next_node = e.dest;
			int next_dist = e.cost + cur_dist;

			if(dist[next_node] < next_dist) continue;

			pq.push({next_node, next_dist});
			dist[next_node] = next_dist;
		}
	}
	return dist;
}

int main(void) {
	// showLine("start");
	// showLine("done");

	freopen("input.txt","r", stdin);

	int N, M, X;
	cin >> N >> M >>X;
	vector<vector<Edge>> mat(N+1, vector<Edge>());
	for(int i=0; i<M; i++) {
		int a, b, c; cin >> a >> b >> c;
		mat[a].push_back({b, c});
	}

	vector<int> xton = dijkstra(N, X, mat);
	vector<vector<int>> ntox(N+1);
	for(int i=1; i<=N; i++) ntox[i] = dijkstra(N, i, mat);

	int answer = 0;
	for(int i=1; i<=N; i++) {
		int tmp = ntox[i][X] + xton[i];
		if(tmp > answer) answer = tmp;
	}

	cout << answer<<"\n";

	return 0;
}