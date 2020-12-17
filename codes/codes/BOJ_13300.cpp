//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int N, K, ans=0;
//    int dat[7][2] = { 0 };
//
//    std::ios::sync_with_stdio(false);
//    
//    cin >> N >> K;
//    for (int i = 0; i < N; i++) {
//        int isMale, grade;
//        cin >> isMale >> grade;
//        dat[grade][isMale]++;
//    }
//    
//    for (int i = 1; i <= 6; i++) 
//        for (int j = 0; j < 2; j++) 
//            if (dat[i][j]) 
//                ans += (1 + (dat[i][j] - 1) / K);
//    
//    printf("%d\n", ans);
//
//    return 0;
//}