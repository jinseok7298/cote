#include <bits/stdc++.h>

using namespace std;

string s;

int cnt0 = 0;
int cnt1 = 0;

int main(){
    cin>>s;

    int num = s[0] - '0';
    if (num == 0) cnt0 ++;
    else cnt1 ++;

    for (int i = 1; i < s.size(); i++){
        num = s[i] - '0';

        if (num == 0 && num != s[i-1] - '0') cnt0 ++;
        else if (num == 1 && num != s[i-1] - '0') cnt1 ++;
        
    }

    if (cnt0 > cnt1) cout<<cnt1<<endl;
    else cout<<cnt0<<endl;
}