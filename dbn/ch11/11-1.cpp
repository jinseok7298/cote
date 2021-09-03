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
        if (fear[i] <= cnt){    //공포도보다 꺼낸 모험가 수가 많으면 그룹에 추가(이전에 꺼낸 모험가의 공포도는 현재 꺼낸 모험가의 공포도 보다 낮으므로 고려 x)
            cnt = 0;    //꺼낸 모험가 수 초기화
            result += 1;
        }
    }

    cout<<result<<endl;

    return 0;
}