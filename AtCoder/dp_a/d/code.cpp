#include <bits/stdc++.h>
using namespace std;

#define INF32 2147483647 // INT
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

    //DP[1] = abs(H[1] - H[0]);
    for (int i = 0; i < N; i++){
        for (int j = 0; j <= W; j++){

            if (j - w[i] >= 0){
                chmax(
                        DP[i+1][j],
                        DP[i][j - w[i]] + v[i]
                        );
            }

            chmax(
                    DP[i + 1][j],
                    DP[i][j]
                    );
        }
    }

    cout << DP[N][W] << endl;
    
}
