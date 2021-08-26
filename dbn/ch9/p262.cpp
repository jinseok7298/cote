#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, start;
vector<pair<int, int> > graph[100001];
int d[100001];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    fill(d, d + 100001, INF);
    
    dijkstra(start);

    int cnt =0;
    int max = 0;

    for (int i = 2; i < n+1; i++){
        if (d[i] != INF) cnt ++;

        if (d[i] > max && d[i] != INF) max = d[i];
    }

    cout<<cnt<<" "<<max<<endl;
}