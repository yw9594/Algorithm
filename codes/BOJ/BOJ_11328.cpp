//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//    int N;
//
//    std::ios::sync_with_stdio(false);
//    cin >> N;
//    while (N--) {
//        bool flag = true;
//        int arr1[26] = { 0 }, arr2[26] = { 0 };
//        string a, b;
//        cin >> a >> b;
//
//        for (int i = 0; i < a.size(); i++) arr1[a[i]-'a']++;
//        for (int i = 0; i < b.size(); i++) arr2[b[i] -'a' ]++;
//
//        for (int i = 0; i < 26 && flag; i++)
//            if (arr1[i] != arr2[i])
//                flag = false;
//            
//        
//        if (flag) printf("Possible\n");
//        else printf("Impossible\n");
//    }
//
//    return 0;
//}