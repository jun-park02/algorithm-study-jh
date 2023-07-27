// 0과 1
// 문자열에 있는 숫자를 전부 같게
// 연속된 하나의 숫자를 잡고 뒤지는것
// 최소 횟수

#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;

    int count[2] = {0, 0};
    int pre = S[0];
    
    cout << pre;

    S[pre]++;

    for (int i = 1; i < S.length(); i++) {
        int current = S[i];

        if (current == pre) {
            continue;
        }
        else {
            count[current]++;
        }
    }

    count[0] <= count[1] ? (cout << count[0]) : (cout << count[1]);

    return 0;
}