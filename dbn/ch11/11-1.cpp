#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> fear;
int result = 0;

int main(){
    cin>>n;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        fear.push_back(x);
    }

    sort(fear.begin(), fear.end());     //공포도 오름차순 정렬

    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt ++;     //꺼낸 모험가 수
        if (fear[i] <= cnt){    //공포도와 꺼낸 모함가 수가 일치하면 그룹에 추가
            cnt = 0;    //꺼낸 모험가 수 초기화
            result += 1;
        }
    }

    cout<<result<<endl;

    return 0;
}