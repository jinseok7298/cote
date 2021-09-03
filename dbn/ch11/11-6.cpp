#include <bits/stdc++.h>

using namespace std;

vector<int> food_times;
long long k;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long times = 0;
    int num = food_times.size();
    int flag = 0;

    while (1){
        int cnt = 0;

        for (int i = 0; i < num; i++){
            if (food_times[i] == 0) cnt += 1;

            if (times == k && food_times[i] > 0) {
                answer = i + 1;
                flag = 1;
                break;
            }
            else if (food_times[i] > 0) {
                food_times[i] = food_times[i] - 1;
                times += 1;
            }
        }

        if (flag == 1) break;

        if (num == cnt) {
            answer = -1;
            break;
        }
    }

    return answer;
}

int main(){
    for (int i = 0; i < 3; i++){
        int x;
        cin>>x;
        food_times.push_back(x);
    }

    cin>>k;

    cout<<solution(food_times, k)<<endl;

}