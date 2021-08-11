#include <iostream>

using namespace std;

int main(){
    int n;
    
    cin>>n;

    int d[n+1];
    d[1] = 0;

    for(int i = 2; i <= n; i++){
        int j;

        d[i] = d[i-1] + 1;

        if (i % 5 == 0){
            j = d[i/5] + 1;
            if (j < d[i]) d[i] = j;
        }
        
        if (i % 3 == 0){
            j = d[i/3] + 1;
            if (j < d[i]) d[i] = j;
        }

        if (i % 2 == 0){
            j = d[i/2] + 1;
            if (j < d[i]) d[i] = j;            
        }
    }

    cout<<d[n]<<endl;

    return 0;
}