#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    clock_t start, end;
    double result;
    start = clock();

    int n, m;       //맵 크기
    int x, y;       //좌표
    int d;          //방향
    int count = 0;      //방문한 칸의 수

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    cin>>n>>m;
    cin>>x>>y>>d;

    vector<vector<int> > map(n);    //맵 생성
                                    //바다: 1, 육지: 0, 방문한 육지: 2
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            cin>>a;
            map[i].push_back(a);
        }
    }

    while(1){
        if (map[y][x] == 0){    //map은 배열 형태로 좌표값 기록시 map[y][x] = (x, y) 값을 나타낸다.
            count += 1;
            map[y][x] = 2;      //현 위치 방문 기록
        }
        int l = 0;      //4방향 다 돌았는지 체크

        for(int i = 0; i < 4; i++){
            l += 1;

            if(d == 3){
                d = 0;
            } else{
                d += 1;
            }
            if (map[y+dy[d]][x+dx[d]] == 0){    //현재의 왼쪽 방향이 안 가본 육지라면 이동
                x = x + dx[d];
                y = y + dy[d];
                break;
            }
        }

        if (l == 4){        //4방향 다 돌았을 때 뒷자리 바다면 while문 종료 아니면 후퇴
            if (d == 0){
                if(map[y+1][x] == 1)
                    break;
                else
                    y = y + 1;
            } else if (d == 1){
                if(map[y][x+1] == 1)
                    break;
                else
                    x = x + 1;
            } else if (d == 2){
                if(map[y-1][x] == 1)
                    break;
                else
                    y = y - 1;
            } else{
                if(map[y][x-1] == 1)
                    break;
                else
                    x = x - 1;
            }
        }
    }

    cout<<count;
    
    end = clock();
    result = (double)(start - end) / CLOCKS_PER_SEC;
    cout<<'\n'<<"실행시간: "<<result<<"sec"<<endl;

    return 0;
}


//동빈씨 풀이
// #include <bits/stdc++.h>

// using namespace std;

// int n, m, x, y, direction;
// // 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
// int d[50][50];
// // 전체 맵 정보
// int arr[50][50];

// // 북, 동, 남, 서 방향 정의
// int dx[] = {-1, 0, 1, 0};
// int dy[] = {0, 1, 0, -1};

// // 왼쪽으로 회전
// void turn_left() {
//     direction -= 1;
//     if (direction == -1) direction = 3;
// }

// int main(void) {
//     // N, M을 공백을 기준으로 구분하여 입력받기
//     cin >> n >> m;
//     // 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
//     cin >> x >> y >> direction;
//     d[x][y] = 1; // 현재 좌표 방문 처리

//     // 전체 맵 정보를 입력 받기
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             int x;
//             cin >> x;
//             arr[i][j] = x;
//         }
//     }

//     // 시뮬레이션 시작
//     int cnt = 1;
//     int turn_time = 0;
//     while (true) {
//         // 왼쪽으로 회전
//         turn_left();
//         int nx = x + dx[direction];
//         int ny = y + dy[direction];
//         // 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
//         if (d[nx][ny] == 0 && arr[nx][ny] == 0) {
//             d[nx][ny] = 1;
//             x = nx;
//             y = ny;
//             cnt += 1;
//             turn_time = 0;
//             continue;
//         }
//         // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
//         else turn_time += 1;
//         // 네 방향 모두 갈 수 없는 경우
//         if (turn_time == 4) {
//             nx = x - dx[direction];
//             ny = y - dy[direction];
//             // 뒤로 갈 수 있다면 이동하기
//             if (arr[nx][ny] == 0) {
//                 x = nx;
//                 y = ny;
//             }
//             // 뒤가 바다로 막혀있는 경우
//             else break;
//             turn_time = 0;
//         }
//     }

//     cout << cnt << '\n';
// }