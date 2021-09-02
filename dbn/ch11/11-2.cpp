#include <bits/stdc++.h>

using namespace std;

string s;
long long result = 0;

int main(){
    cin>>s;

    for(int i = 0; i < s.size(); i++){
        int num = s[i] - '0';

        if (num <= 1 || result <= 1) {
            result += num;
        }
        else {
            result *= num;
        }
    }

    cout<<result<<endl;
}