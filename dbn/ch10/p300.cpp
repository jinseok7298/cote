#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[100001];

vector<pair<int, pair<int, int> > > edges;
int result = 0;

int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {
    int max = 0;
    cin>>n>>m;

    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for (int i = 0; i < m; i++){
        int a, b, cost;
        cin>>a>>b>>cost;
        edges.push_back(make_pair(cost, make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
            if (cost > max) max = cost;    //edges는 오름차순으로 정리되므로 굳이 max 설정을 하지않고 마지막 cost를 빼줘도 됨
        }
    }
    
    result -= max;

    cout<<result<<endl;

    return 0;
}