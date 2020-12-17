//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//	int cnt1[26] = { 0 }, cnt2[26] = { 0 }, ans = 0;
//	string a, b;
//
//	std::ios::sync_with_stdio(false);
//	cin >> a >> b;
//
//	for (int i = 0; i < a.size(); i++) cnt1[a[i] - 'a']++;	
//	for (int i = 0; i < b.size(); i++) cnt2[b[i] - 'a']++;
//
//	for (int i = 0; i < 26; i++) ans += abs((cnt1[i] - cnt2[i])); 
//
//	printf("%d\n", ans);
//	return 0;
//}