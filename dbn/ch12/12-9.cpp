#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    int min = 1000;

    for (int i = 1; i < (s.size()/2) + 1; i++){
        int length = s.size();
        int cnt = 0;
        string now = s.substr(0, i);

        for (int j = i; j + i <= s.size(); j += i){
            string next = s.substr(j, i);
            
            if (now == next) {
                length -= i;
                cnt = 1;
            }
            else {
                length += cnt;
                cnt = 0;
            }
            now = next;
        }

        if (cnt == 1) {
            length += cnt;
        }

        if (length < min) min = length;
    }

    answer = min;

    return answer;
}