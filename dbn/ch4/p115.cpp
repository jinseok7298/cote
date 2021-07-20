#include <iostream>
#include <time.h>

using namespace std;

int main(){
    clock_t start, end;
    double result;
    start = clock();

    int x, y;
    int count = 0;    //경우의 수
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char b;

    cin>>b>>y;     //나이트 위치 입력

    for(int i = 0; i < 8; i++){     //나이트 열 위치를 숫자로 표현
        if(a[i] == b){
            x = i + 1;
        }
    }

    if (y > 2){    //위로 2칸 이동 가능
        if (x > 1)    //좌로 1칸
            count ++;
        if (x < 8)    //우로 1칸
            count ++;
    }

    if (y < 7){    //아래 2칸
        if (x > 1)      //좌 1칸
            count ++;
        if (x < 8)      //우 1칸
            count ++;
    }

    if (x > 2){     //좌 2칸
        if (y > 1)      //위 1칸
            count ++;
        if (y < 8)      //아래 1칸
            count ++;
    }

    if (x < 7){     //우 2칸
        if (y > 1)      //위 1칸
            count ++;
        if (y < 8)      //아래 1칸
            count ++;
    }

    cout<<count;

    end = clock();
    result = (double)(start - end) / CLOCKS_PER_SEC;
    cout<<'\n'<<"실행시간: "<<result<<"sec"<<endl;

    return 0;
}


//동빈씨 해답

// #include <bits/stdc++.h>

// using namespace std;

// string inputData;

// // 나이트가 이동할 수 있는 8가지 방향 정의
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

// int main(void) {
//     // 현재 나이트의 위치 입력받기
//     cin >> inputData;
//     int row = inputData[1] - '0';
//     int column = inputData[0] - 'a' + 1;

//     // 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
//     int result = 0;
//     for (int i = 0; i < 8; i++) {
//         // 이동하고자 하는 위치 확인
//         int nextRow = row + dx[i];
//         int nextColumn = column + dy[i];
//         // 해당 위치로 이동이 가능하다면 카운트 증가
//         if (nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
//             result += 1;
//         }
//     }

//     cout << result << '\n';
//     return 0;
// }