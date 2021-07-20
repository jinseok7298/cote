#include <iostream>
#include <time.h>

using namespace std;

int main(){
    clock_t start, end;
    double result;
    start = clock();

    int n;
    int count = 0;

    cin>>n;

    for(int h = 0; h <= n; h++){
        for(int m = 0; m < 60; m++){
            for(int s = 0; s < 60; s++){
                if((h % 10) == 3){
                    count += 1;
                    continue;
                } else if((m % 10) == 3 || (m / 10) == 3){
                    count += 1;
                    continue;
                } else if((s % 10) == 3 || (s / 10) == 3){
                    count += 1;
                    continue;
                }
            }
        }
    }

    cout<<count;

    end = clock();
    result = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<'\n'<<"실행 시간: "<<result<<"sec"<<endl;     //실행시간 출력

    return 0;
}


//동빈씨 해설

// #include <bits/stdc++.h>

// using namespace std;

// int h, cnt;

// // 특정한 시각 안에 '3'이 포함되어 있는지의 여부
// bool check(int h, int m, int s) {
//     if (h % 10 == 3 || m / 10 == 3 || m % 10 == 3 || s / 10 == 3 || s % 10 == 3)
//         return true;
//     return false;
// }

// int main(void) {
//     // H를 입력받기 
//     cin >> h;
//     for (int i = 0; i <= h; i++) {
//         for (int j = 0; j < 60; j++) {
//             for (int k = 0; k < 60; k++) {
//                 // 매 시각 안에 '3'이 포함되어 있다면 카운트 증가
//                 if (check(i, j, k)) cnt++;
//             }
//         }
//     }
//     cout << cnt << '\n';
//     return 0;
// }