#include <iostream>

// int fibo(int x) {
//     if (x == 1 || x == 2) {
//         return 1;
//     }

//     return fibo(x - 1) + fibo(x - 2);
// }

// int main(void) {
//     std::cout << fibo(4) << "\n";
//     return 0;
// }

// ---------------------------------------------
// DP를 사용해서 풀기
// ---------------------------------------------

long long dp[100];

int fibo(int x) {
    if (x == 1 || x == 2) {
        return 1;
    }
    if (dp[x] != 0) {
        return dp[x];
    }
    return dp[x] = fibo(x - 1) + fibo(x - 2);
}

int main(void) {
    int N;
    std::cin >> N;
    std::cout << fibo(N);
}