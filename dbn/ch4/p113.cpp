#include <iostream>
#include <time.h>

using namespace std;

int main(){
    clock_t start, end;
    double result;
    start = clock();

    int n;
    int count = 0;

    cin>>n;

    for(int h = 0; h <= n; h++){
        for(int m = 0; m < 60; m++){
            for(int s = 0; s < 60; s++){
                if((h % 10) == 3){
                    count += 1;
                    continue;
                } else if((m % 10) == 3 or (m / 10) == 3){
                    count += 1;
                    continue;
                } else if((s % 10) == 3 or (s / 10) == 3){
                    count += 1;
                    continue;
                }
            }
        }
    }

    cout<<count;

    end = clock();
    result = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<'\n'<<"실행 시간: "<<result<<"sec"<<endl;     //실행시간 출력

    return 0;
}