#include <bits/stdc++.h>

using namespace std;

vector<int> food_times;
long long k;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long times = 0;
    int num = food_times.size();    //음식 수
    int flag = 0;       //while문 종료를 위한 신호

    while (1){
        int cnt = 0;    //다 먹은 음식 수 세는 변수

        for (int i = 0; i < num; i++){

            if (times == k && food_times[i] > 0) {      //현재 시간과 방송사고 시간 일치 & 먹을 음식 번호
                answer = i + 1;     //방송 사고 후 먹을 음식 번호
                flag = 1;       //while 종료를 위한 신호 값
                break;
            }
            else if (food_times[i] == 0) cnt += 1;   //음식 다 먹었다면 먹은 음식 수 카운트
            else if (food_times[i] > 0) {     //음식을 먹을 수 있을 경우
                food_times[i] = food_times[i] - 1;
                times += 1;     //음식 먹고 시간 +1
            }
        }

        if (flag == 1) break;

        if (num == cnt) {       //음식수 = 다먹은 음식 수인 경우 종료
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