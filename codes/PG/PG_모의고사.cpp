#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것

vector<int> solution(vector<int> answers) {
    vector<int> answer;
	
	int n= answers.size();
	vector<int> student[3] = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
	for(int i=0; i<3; i++) {
		int lim = student[i].size();
		for(int j=lim, k=0; j<n; j++, k=(k+1)%lim){
			student[i].push_back(student[i][k]);
		}
	}

	int cnt[3]={0,}, max_cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			if(answers[i]==student[j][i]){
				cnt[j]++;
				if(cnt[j]>max_cnt) max_cnt=cnt[j];
			}
		}
	}
	for(int j=0; j<3; j++) if(cnt[j]==max_cnt) answer.push_back(j+1);

	sort(answer.begin(), answer.end());
    return answer;
}

int main(void) {
	// input
	// freopen("./input.txt", "r", stdin);
	// std::istream::sync_with_stdio(false);
	// cin.tie(NULL);
	
	vector<int> ans = solution({1,2,3,4,5});

	return 0;
}