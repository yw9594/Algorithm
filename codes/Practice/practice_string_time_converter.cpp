#include <iostream>
#include <vector>
#include <string>
#include <sstream>   // ex) stringstream


using namespace std;

// 프로그래머스 사용 시 전역 변수는 반드시 solution 내부에서 초기화 할 것
vector<string> split(string & str, char delim=' '){
	stringstream ss(str);
	vector<string> toks;
	string tok;

	while(getline(ss, tok, delim)) toks.push_back(tok);

	return toks;
}
struct TimeConverter{
	// HH:MM:SS -> second
	static int HMSToSecond(string & time, char delim=':'){ 
		vector<string> toks = split(time, delim);
		int h = stoi(toks[0]), m = stoi(toks[1]), s = stoi(toks[2]);
		return h*60*60 + m*60 + s; 
	}

	// SS.MSMSMS -> mili second
	static int SMStoMS(string & time, char delim='.'){ 
		int ret=0;
		vector<string> toks = split(time, delim);

		ret = stoi(toks[0]) * 1000;
		if(toks.size()==2) { // ms 3자릿수 만들기 ex) 10.3 -> 10.300
			while(toks[1].size()!=3) toks[1] += "0";
			ret += stoi(toks[1]);
		}
		return ret;
	}
	
	// Second -> HH:MM:SS
	static string SecondToTime(int second, char delim=':'){
		string ret="";
		string h = to_string(second / (60*60)), 
			   m = to_string((second % (60*60))/60), 
			   s = to_string((second % (60*60))%60);
		if(h.size()!=2) h = "0" + h;
		if(m.size()!=2) m = "0" + m;
		if(s.size()!=2) s = "0" + s;
		ret = h + delim + m + delim + s;
		return ret;
	}
};

int main(void) {
	cout << "1. HH:MM:SS to Second" << "\n";
	vector<string> time = {"00:00:00", "10:00:00", "23:59:59", "10:53:49"};
	for(auto & t : time) cout << TimeConverter::HMSToSecond(t)<<" "; cout <<"\n\n";

	cout << "2. SS.MSMSMS to MiliSecond" << "\n";
	time = {"0", "10.32", "10.032", "10.3", "10.30", "10.300", "10"};
	for(auto & t : time) cout << TimeConverter::SMStoMS(t)<<" "; cout <<"\n\n";

	cout << "3. Second to HH:MM:SS" << "\n";
	cout << TimeConverter::SecondToTime(86400)<<"\n";
	cout << TimeConverter::SecondToTime(39229)<<"\n\n";
	return 0;
}