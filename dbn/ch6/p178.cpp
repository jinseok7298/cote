#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    vector<int> v;

    cin>>n;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i = n - 1; i >= 0; i--){
        cout<<v[i]<<" ";
    }

    return 0;
}