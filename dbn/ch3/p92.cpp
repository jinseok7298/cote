#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, k;
    vector<int> v;

    cin>>n>>m>>k;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    int first = v[n-1];
    int second = v[n-2];

    int result = 0;

    while(1){
        if (m >= k){
            for(int i = 0; i < k; i++){
                result += first;
                m -= 1;
            }
            if (m > 0)
                result += second;
                m -= 1;
        } else{
            for(int i = 0; i < m; i++){
                result += first;
            }
            break;
        }
    }

    cout<<"답: "<<result<<endl;

    // 모범 답안
    // 가장 큰 수가 더해지는 횟수 계산
    // int cnt = (m / (k + 1)) * k;
    // cnt += m % (k + 1);

    // int result = 0;
    // result += cnt * first; // 가장 큰 수 더하기
    // result += (m - cnt) * second; // 두 번째로 큰 수 더하기

    // cout<<"답: "<<result<<endl;
}