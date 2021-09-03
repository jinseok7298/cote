#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main(){
    cin>>n;

    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int result = 1;
    int flag = 0;

    while(1){
        int cnt = result;

        for (int i = n-1; i >= 0; i--){     //큰 화폐부터 계산
            if (i == 0 && cnt - v[i] != 0) {    //현재 금액 - 가장 작은 화폐 단위 값이 0으로 떨어지지 않는다면 결과 출력
                cout<<result<<endl;
                flag = 1;       //while 반복문 종료하기 위한 신호
            }
            else if (cnt - v[i] < 0) continue;      //현재 금액 - 화폐 단위 값이 음수면 다음 화폐(더 작음) 계산
            else if (cnt - v[i] > 0) cnt = cnt - v[i];      //현재 금액 - 화폐 단위 값이 양수면 현재 금액에서 화폐 단위만 큼 빼주고 다음 화폐로 계산 
            else break; 
        }

        if (flag == 1) break;   //만들 수 없는 금액 탐지하면 종료

        result ++;
    }
}