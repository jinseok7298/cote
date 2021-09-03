#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
int result = 0;

int main(){
    cin>>n>>m;

    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (v[i] != v[j]) result += 1;
        }
    }

    cout<<result<<endl;
}