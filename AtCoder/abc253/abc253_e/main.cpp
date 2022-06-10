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


int N, M, K;

long long CUMSUM1[5011];
const long long MOD = 998244353;
long long DP[1010][5010] = {};


void solve() {
    cin >> N >> M >> K;
    // vector<vector<long long>> DP(N, vector<long long>(M, 0));

    for (int i = 0; i < M; i++){
        DP[0][i] = 1;
    }

    for (int i = 0; i < N - 1; i++){
        CUMSUM1[0] = 0;
        for (int j = 0; j < M; j++){
            CUMSUM1[j + 1] = CUMSUM1[j] + DP[i][j];
            CUMSUM1[j + 1] %= MOD;
        }
            
        for (int j = 0; j < M; j++){

            DP[i + 1][j] = CUMSUM1[M];

            if (K > 0)
            {
                DP[i + 1][j] -= CUMSUM1[min(j + K, M)] - CUMSUM1[max(j - K + 1, 0)];
            }

            DP[i + 1][j] += MOD;
            DP[i + 1][j] %= MOD;
        }

    }

    long long ans = 0;

    for (int i = 0; i < M; i++){
        ans += DP[N - 1][i];
    }
    ans %= MOD;

    cout << ans << endl;


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K][0] << " " << DP[K][1] << endl;
}

