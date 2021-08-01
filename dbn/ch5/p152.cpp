#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> map[200];

// 상. 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //상, 하, 좌, 우 순서로 bfs탐색
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //맵 벗어난 경우 무시
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            //괴물 만난 경우 무시
            if (map[nx][ny] == 0) continue;

            //방문 안 한 노드 최단 거리 기록
            if (map[nx][ny] == 1){
                map[nx][ny] = map[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    
    cout<<map[n-1][m-1]<<endl;
}

int main(){

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            scanf("%1d", &x);
            map[i].push_back(x);
        }
    }

    bfs(0, 0);

    return 0;
}