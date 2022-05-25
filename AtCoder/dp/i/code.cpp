#include <bits/stdc++.h>
using namespace std;

#define INF32 2147483647 // INT
#define INF64 9223372036854775807  // long long
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
    if (a < b) {
        a = b;  // aをbで更新
        return true;
    }
    return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
    if (a > b) {
            a = b;  // aをbで更新
            return true;
        }
    return false;
}

int N;
double P[3002];
double DP[3020][3020];

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> P[i];
    }
    
    DP[0][0] = 1;

    for (int i = 1; i < N + 1; i++){
        for (int j = 0; j < i + 1; j++){
            if (j == 0){
                DP[i][j] = DP[i - 1][j] * (1 - P[i - 1]);
            } else {
                DP[i][j] = DP[i - 1][j] * (1 - P[i - 1]) + 
                            DP[i - 1][j - 1] * P[i - 1];
            }
        }
    }

    double ans = 0;
    for (int i = N / 2 + 1; i < N + 1; i++){
        ans += DP[N][i];
    }
    
    printf("%.10f\n", ans);

}
