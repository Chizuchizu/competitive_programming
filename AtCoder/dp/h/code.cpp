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
float P[3000];
int DP[1005][1005];

int main(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> P[i];
    }
    for (int i = 0; i < 1005; i++){
        DP[0][i] = 1;
    }
    
    DP[0][0] = 1;

    for (int i = 1; i < N+1; i++){
        for (int j = 0; j < i+1; i++){
            if (j == 0){
                DP[i][j] = DP[i - 1][j - 1];
            } else {
                DP[i][j] = max(
                            DP[i - 1][j] * (1 - P[j]),
                            DP[i - 1][j - 1] * P[j]
                        );
            }
        }
    }
    
    cout << DP[N][N] << endl;

}
