#include <bits/stdc++.h>

using namespace std;

string n;

int main(){
    cin>>n;

    int x = 0;
    int y = 0;

    for(int i = 0; i < n.size(); i++){
        if (i < n.size()/2){
            x += n[i] - '0';
        }
        else {
            y += n[i] -'0';
        }
    }

    if (x == y) cout<<"LUCKY"<<endl;
    else cout<<"READY"<<endl;
    
}