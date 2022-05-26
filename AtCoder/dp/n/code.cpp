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
vector<long long> A(400);
long long DP[500][500];
long long CUMSUM[401];


long long rec(int from, int to){
    // [from, to)
    // 計算済み
    if (DP[from][to] != INF64) return DP[from][to];

    if (abs(to - from) <= 1) return A[from];


    long long res = INF64;
    for (int mid = from + 1; mid <= to - 1; mid++){
        long long rec1 = rec(from, mid);
        long long rec2 = rec(mid, to);
        chmin(
                res,
                rec(from, mid) + rec(mid, to)
        );
    }
    long long cum = CUMSUM[to] - CUMSUM[from];
    res += cum;

    // cout << from << " " << to << " " << cum << endl;

    DP[from][to] = res;
    // cout << from << " " << to << " " << res << endl;
    return res;
}

void solve() {

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
        CUMSUM[i + 1] = CUMSUM[i] + A[i];
    }
    for (int i = 0; i < 500; i++){
        for (int j = 0; j < 500; j++){
            DP[i][j] = INF64;
        }
    }
    
    long long ans;

    ans = rec(0, N) - CUMSUM[N];
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K][0] << " " << DP[K][1] << endl;
}
