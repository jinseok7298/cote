#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[100001];

int findParent(int x){
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void) {

    cin>>n>>m;

    for(int i = 0; i < n + 1; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>c>>a>>b;

        if (c == 0) unionParent(a, b);
        else if (c == 1) {
            if (findParent(a) == findParent(b)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}
