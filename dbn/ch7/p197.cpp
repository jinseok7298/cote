#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr, require;

// 이진 탐색 소스코드 구현(반복문)
string binarySearch(vector<int>& arr, int target, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        // 찾은 경우 중간점 인덱스 반환
        if (arr[mid] == target) return "yes";
        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if (arr[mid] > target) end = mid - 1;
        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else start = mid + 1; 
    }
    return "no";
}

int main(){
    
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    cin>>m;
    for(int i = 0; i < m; i++){
        int x;
        cin>>x;
        require.push_back(x);
    }

    for(int i = 0; i < m; i++){
        cout<<binarySearch(arr, require[i], 0, n-1)<<" ";
    }


    return 0;
}