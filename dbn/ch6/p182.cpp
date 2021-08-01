#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int result = 0;
    int n, k;
    vector<int> a, b;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        a.push_back(x);
    }

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < k; i++){
        int j = n - (1+i);
        if(a[i] < b[j]){
            int temp = a[i];
            a[i] = b[j];
            b[j] = temp;
        }
    }

    for(int i = 0; i < n; i++){
        result += a[i];
    }

    cout<<result<<endl;

    return 0;
}