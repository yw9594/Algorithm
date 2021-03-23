#include <iostream>

#include <algorithm>
#include <vector>

#include <string>

using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것.

struct TimeConverter{
	static int toMinute(string t){
		string h =t.substr(0, 2), m = t.substr(3, 2);
		return stoi(h) * 60 + stoi(m); 
	}
	static string toStrTime(int t){
		string h = to_string(t/60), m = to_string(t%60);
		if(h.length()<2) h = "0" + h;
		if(m.length()<2) m = "0" + m;
		
		return h+":"+m; 
	}
};


string solution(int n, int t, int m, vector<string> timetable) {
	int konTime=-1;
    string answer = "";

	vector<int> crew;
	for(auto & t : timetable) crew.push_back(TimeConverter::toMinute(t));
	sort(crew.begin(), crew.end());

	vector<int> bus;
	for(int i=0; i<n; i++) bus.push_back(540 + t*i);
	
	int b_i=0, c_i=0; // 현재 버스, 현재 승객
	while(b_i<n){
		int o_c_i=c_i; 									// 현재 탑승 승객

		while((c_i - o_c_i)<m && c_i<crew.size() && crew[c_i]<=bus[b_i]) { // 가득차거나 승객이 없을 때까지
			c_i++; 
		}

		if((c_i - o_c_i)==m) { // 현재 버스가 승객을 다 태운 경우, 가장 마지막 승객보다 1분 줄선다.
			konTime = crew[c_i-1]-1;
		}
		else{ // 버스가 승객을 다 못태운 경우, 버스 시간에 맞춰 탄다.
			konTime = bus[b_i];
		}
		b_i++;
	}
	answer = TimeConverter::toStrTime(konTime);

    return answer;
}

int main(void) {
	// input
	/*freopen("input.txt", "r", stdin);
	std::istream>::sync_with_stdio(false);
	cin.tie(NULL);
	*/

	cout << solution(1,1,5, {"08:00", "08:01", "08:02", "08:03"})<<"\n"; 
	cout << solution(10, 60, 45, {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"})<<"\n";
	cout << solution( 2, 10, 2, {"09:10", "09:09", "08:00"})<<"\n";

	return 0;
}