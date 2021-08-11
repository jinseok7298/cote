#include <iostream>
#include <vector>

using namespace std;

int n;
int d[100];
vector<int> v;

int main(){
    int max = 0;

    cin>>n;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    d[0] = v[0];
    d[1] = v[1];
    d[2] = v[0] + v[2];

    for(int j = 0; j < n; j++){
        
        if (j >= 3) {
            if (d[j-2] > d[j-3]) {
                d[j] = v[j] + d[j-2];
            } 
            else {
                d[j] = v[j] + d[j-3];
            }
        }

        if(max < d[j]) max = d[j];
    }

    cout<<max<<endl;

    return 0;
}