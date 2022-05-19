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



int N, W;
long long w[101], v[101];
long long  DP[110][100010];

int main(){
    cin >> N >> W;
    for (int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
        // cout << H[i] << endl;
    }
    for (int i = 0; i < 110; i ++ ){
        for (int j = 0; j < 100010; j++){
            DP[i][j] = INF32;
        }
    }
    DP[0][0] = 0;

    //DP[1] = abs(H[1] - H[0]);
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= 100000; j++){

            if (j - v[i] >= 0){
                chmin(
                        DP[i+1][j],
                        DP[i][j - v[i]] + w[i]
                        );
            }

            chmin(
                    DP[i + 1][j],
                    DP[i][j]
                    );
        }
    }

    long long ans = 0;

    for (int i = 0; i <= 100000; i++){
        if (DP[N][i] <= W){
            ans = i;
        }
    }

    cout << ans << endl;

    
}
