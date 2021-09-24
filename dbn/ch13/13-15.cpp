#include <bits/stdc++.h>

using namespace std;

int n, m, k, x;
vector<int> graph[300001];
vector<int> d(300001, 0);

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if(d[next] == 0 && next != start) {
                d[next] = d[now] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    cin>>n>>m>>k>>x;

    for (int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    bfs(x);

    int flag = 0;
    for (int i = 1; i <= n; i++){
        if (d[i] == k) {
            cout<<i<<endl;
            flag = 1;
        }
    }
    
    if (flag == 0) cout<<-1<<endl;
}