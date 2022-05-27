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

int W, N, K;
int AB[50][2];
int DP[60][10100][60];



void solve() {
    memset(DP, 0, sizeof(DP));

    cin >> W >> N >> K;

    for (int i = 0; i < N; i++){
        cin >> AB[i][0] >> AB[i][1];
    }

    // i個まで使ってk個使った時の幅j以下の最大重要度

    for (int i = 0; i < N; i++){
        for (int j = 0; j < W + 2; j++){
            for (int k = 0; k <= K; k++){
                int a = AB[i][0];  // 幅
                int b = AB[i][1];  // 優先度
                if (j - a >= 0){
                    chmax(
                            DP[i+1][j][k+1],
                            DP[i][j - a][k] + b
                         );
                } 
                   
                
                chmax(
                        DP[i + 1][j][k],
                        DP[i][j][k]
                     );
            }
            /*
            chmax(
                    DP[i + 1][j + AB[i][0]], 
                    DP[i][j] + AB[i][1]
                );
                */

        }
    }
    /*
    for (int i = 0; i < K; i++){
        cout << DP[N][W][i] << endl;
    }
    */


    cout << DP[N][W][K] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K][0] << " " << DP[K][1] << endl;
}
