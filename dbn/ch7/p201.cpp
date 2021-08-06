#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v;

int main(){
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    int max = 1;

    while(1){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if (v[i] > max) cnt += v[i] - max;
        }

        if (cnt == m) break;

        if (cnt < m) {
            max--;
            break;
        }

        max ++;

    }

    cout<<max;


    return 0;
}