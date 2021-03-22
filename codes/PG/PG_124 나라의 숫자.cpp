// Headers
#include <iostream>
#include <list>
#include <string>

using namespace std;

string toTernary(int n){
	list<char> tmp;
	string ret;
	int a=n, b=0;
	while(a!=0){
		b = a % 3;
		a /= 3;
		if(b==0) a--;
		tmp.push_front( b +'0');
	}
	ret.assign(tmp.begin(), tmp.end());
	return ret;
}
void toOneTwoFour(string & str){
	for(auto & c : str){
		switch(c){
			case '0': c = '4'; break;
			case '1': c = '1'; break;
			case '2': c = '2'; break;
		}
	}
}

string solution(int n) {
	string answer = toTernary(n);
	toOneTwoFour(answer);

    return answer;
}