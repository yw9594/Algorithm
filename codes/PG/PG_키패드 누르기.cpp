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

struct Pos{
	int i, j;
};

inline int getDist(Pos & a, Pos & b) {
	return abs(a.i-b.i) + abs(a.j-b.j);
}

string solution(vector<int> numbers, string hand) {
 	string answer = "";
	int flag = hand.compare("left")==0? 0 : 1;
	Pos numberPos[10] = {
		{3, 1},
		{0, 0}, {0, 1}, {0, 2},
		{1, 0}, {1, 1}, {1, 2},
		{2, 0},	{2, 1},	{2, 2},	
	};
	Pos left={3, 0}, right={3, 2};

	for(int & n : numbers) {
		char cn = '0' + n;
		if(strchr("147", cn)) {
			answer += 'L';
			left = numberPos[n];
		}
		else if(strchr("369", cn)) {
			answer += 'R';
			right = numberPos[n];
		}
		else {
			int leftDist = getDist(left, numberPos[n]);
			int rightDist = getDist(right, numberPos[n]);
			if(leftDist==rightDist) {
				if(flag==0) {
					answer += 'L';
					left = numberPos[n];				
				}
				else {
					answer += 'R';
					right = numberPos[n];
				}
			}
			else {
				if(leftDist<rightDist) {
					answer += 'L';
					left = numberPos[n];
				}
				else{
					answer += 'R';
					right = numberPos[n];
				}
			}
		}
		cout <<n <<" ";
		cout << left.i<<" "<<left.j<<" ";
		cout << right.i<<" "<<right.j<<"\n";
	}
    return answer;
}

int main(void) {
	showLine("start");

	// cout << solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5},	"right")<<"\n";
	// cout << "LRLLLRLLRRL" <<"\n";
	cout << solution({7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2},	"left")<<"\n";
	cout << "LRLLRRLLLRR" <<"\n";

	showLine("done");
	return 0;
}