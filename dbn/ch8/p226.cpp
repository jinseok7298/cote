#include <iostream>
#include <vector>

using namespace std;

int n, m;
int d[101];
vector<int> v;

int main(){
    cin>>n>>m;

    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    for (int i = 1; i <= m; i++){
        for (int j = 0; j < n; j++){
            if (i == v[j]) {        //화폐 가치와 금액 일치하는 경우
                d[i] = 1;
                break;
            }

            if (i - v[j] < 0 && d[i] == 0) {    //화폐 가치보다 금액이 작고, 화폐 개수를 구하지 않은 경우
                d[i] = -1;
                break;
            }

            if (d[i] <= 0 && d[i - v[j]] == -1){     //화폐로 원하는 금액을 만드느게 불가능한 경우
                d[i] = -1;
            }
            else if (d[i - v[j]] != -1){
                if (d[i] <= 0 && i - v[j] > 0) {       //원하는 금액을 만드는게 가능한 경우
                    d[i] = d[i - v[j]] + 1;
                }
                else{
                    d[i] = min(d[i], d[i - v[j]] + 1);      //다른 경우와 비교해서 적은 횟수로 기록
                }
            }
            //cout<<"j = "<<j<<"반복문"<<d[i]<<endl;
        }
        //cout<<"i = "<<i<<"반복문"<<d[i]<<endl;

    }

    cout<<d[m]<<endl;


    return 0;
}