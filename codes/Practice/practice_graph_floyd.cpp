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

#define INF 99999999

int main(void) {
	// showLine("start");

	// showLine("done");

	freopen("input.txt", "rt", stdin);

	int N, M;
	cin>>N>>M;

	vector<vector<int>> mat(N+1, vector<int>(N+1, INF));
	for(int i=0; i<M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mat[a][b] = c < mat[a][b] ? c : mat[a][b];
	}

	// 플로이드 알고리즘
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				mat[i][j] = (mat[i][j] < mat[i][k] + mat[k][j])  ? mat[i][j] : mat[i][k] + mat[k][j];
			}
		}
	}
	for(int i=1; i<=N; i++) mat[i][i] = 0; // 자기 자신에게 돌아오는 경로는 항상 0이다.


	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cout << (mat[i][j] != INF ? mat[i][j] : 0) <<" ";
		cout <<"\n";
	}

	return 0;
}