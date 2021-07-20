#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    clock_t start, end;
    double result;
    start = clock();

    int x = 1;
    int y = 1;     //초기값 (1, 1)
    int n;
    vector<char> v;
    char a;

    cin>>n;     //N 입력
    cin.get(a);

    while(1){
        cin.get(a);

        if(a == '\n') break;    //2번째 줄 입력 끝
        
        v.push_back(a);
    }

    for(int i = 0; i < v.size(); i++){   //R, L, U, D에 따라 좌표값 변경
        switch(v[i]){
            case 'U':
                if((x-1) > 0)
                    x -= 1;
                break;
            case 'D':
                if(x < n)
                    x += 1;
                break;
            case 'L':
                if((y-1) > 0)
                    y -= 1;
                break;
            case 'R':
                if(y < n)
                    y += 1;
                break;
        }
    }

    cout<<x<<" "<<y;  //좌표값 출력

    end = clock();
    result = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<'\n'<<"실행 시간: "<<result<<"sec"<<endl;     //실행시간 출력

    return 0;
}



//동빈씨 해설
  
// #include <bits/stdc++.h>

// using namespace std;

// // N을 입력받기
// int n;
// string plans;
// int x = 1, y = 1;

// // L, R, U, D에 따른 이동 방향 
// int dx[4] = {0, 0, -1, 1};
// int dy[4] = {-1, 1, 0, 0};
// char moveTypes[4] = {'L', 'R', 'U', 'D'};

// int main(void) {
//     cin >> n;
//     cin.ignore(); // 버퍼 비우기 
//     getline(cin, plans);
//     // 이동 계획을 하나씩 확인
//     for (int i = 0; i < plans.size(); i++) {
//         char plan = plans[i];
//         // 이동 후 좌표 구하기 
//         int nx = -1, ny = -1;
//         for (int j = 0; j < 4; j++) {
//             if (plan == moveTypes[j]) {
//                 nx = x + dx[j];
//                 ny = y + dy[j];
//             }
//         }
//         // 공간을 벗어나는 경우 무시 
//         if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
//         // 이동 수행 
//         x = nx;
//         y = ny;
//     }
//     cout << x << ' ' << y << '\n';
//     return 0;
// }