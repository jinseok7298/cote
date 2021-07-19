#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    clock_t start, end;
    double result;
    start = clock();

    int x = 1;
    int y = 1;     //초기값 (1, 1)
    int n;
    vector<char> v;
    char a;

    cin>>n;     //N 입력
    cin.get(a);

    while(1){
        cin.get(a);

        if(a == '\n') break;    //2번째 줄 입력 끝
        
        v.push_back(a);
    }

    for(int i = 0; i < v.size(); i++){   //R, L, U, D에 따라 좌표값 변경
        switch(v[i]){
            case 'U':
                if((x-1) > 0)
                    x -= 1;
                break;
            case 'D':
                if(x < n)
                    x += 1;
                break;
            case 'L':
                if((y-1) > 0)
                    y -= 1;
                break;
            case 'R':
                if(y < n)
                    y += 1;
                break;
        }
    }

    cout<<x<<" "<<y;  //좌표값 출력

    end = clock();
    result = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<'\n'<<"실행 시간: "<<result<<"sec"<<endl;     //실행시간 출력

    return 0;
}