#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF32 2147483647 // INT
#define INF64 9223372036854775807  // long long

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b) - 1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

#define pb push_back

#define endl '\n'


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


int N, Ma, Mb;

int A[40];
int B[40];
int C[40];

int DP[42][410][410];


void solve() {
    // DP[n][i][j] n個のうちタイプaをi(g), bをj(g)にする最小の予算


    cin >> N >> Ma >> Mb;
    rep(i, N) {
        cin >> A[i] >> B[i] >> C[i];
    }
    int a, b, c;

    rep(i, 42){
        rep(j, 410){
            rep(k, 410){
                DP[i][j][k] = INF32 / 2;
            }
        }
    }

    DP[0][0][0] = 0;


    rep(n, N) {
        a = A[n];
        b = B[n];
        c = C[n];
        rep(i, 401) {
            rep(j, 401) {

                chmin(
                        DP[n + 1][i][j],
                        DP[n][i][j]
                     );
                if (i - a >= 0 && j - b >= 0) {
                    chmin(
                            DP[n + 1][i][j],
                            DP[n][i - a][j - b] + c
                         );
                }
            }
        }
    }

    int ans = INF32 / 2;
    for (int i = 1; i < 401; i++) {
        for (int j = 1; j < 401; j++) {
            if (j * Ma == Mb * i) {
//                cout << i << " " << j << " " << endl;
                chmin(
                        ans,
                        DP[N][i][j]
                     );
            }
        }
    }
    if (ans == INF32 / 2) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K][0] << " " << DP[K][1] << endl;
}

