#include <bits/stdc++.h>

using namespace std;

int n;
int indegree[501];
int times[501];
vector<int> graph[501];
int result[501];

void topologySort() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            result[i] = times[i];
        }
    }

    while (!q.empty()) {
        int now = q.front();
        cout<<result[now]<<endl;
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]] -= 1;

            if (result[graph[now][i]] < result[now] + times[graph[now][i]]) result[graph[now][i]] = result[now] + times[graph[now][i]];
            
            if (indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]);
            }
        }
    }
}

int main(void) {
    cin>>n;

    for (int i = 1; i <= n; i++) {
        int a;
        int x = 0;
        cin>>a;
        times[i] = a;
        
        while (x != -1) {
            cin >> x;
            if (x == -1) break;
            graph[x].push_back(i);
            indegree[i] += 1;
        }
    }

    topologySort();
}