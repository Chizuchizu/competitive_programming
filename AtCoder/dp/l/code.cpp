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
long long A[3000];
long long DP[3005][3005];


long long rec(int from, int to){
    // [from, to)
    // 計算済み
    if (DP[from][to] != INF64) return DP[from][to];
    int flag = (N - to + from + 2) % 2;

    /*
    if (abs(from - to) <= 1) {
        return -flag * A[from];
    }
    */
    if (to <= from) return 0;
    // 0, Nで0 -> 先手
    // 1, Nで1 -> 後手
    //
    long long res = -1;

    if (flag == 1){
        // 後手, X - Yの最小化
        res = INF64;
        chmin(res, rec(from, to - 1) - A[to - 1]);
        chmin(res, -A[from] + rec(from + 1, to));
    } else {
        // 先手, X - Yの最大化
        res = -INF64;
        chmax(res, rec(from, to - 1) + A[to - 1]);
        chmax(res, A[from] + rec(from + 1, to));
    }

    DP[from][to] = res;

    return res;
}


void solve() {
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    for (int i = 0; i < 3005; i++){
        for (int j = 0; j < 3005; j++){
            DP[i][j] = INF64;
        }
    }

    long long ans = rec(0, N);
    cout << ans << endl;
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K][0] << " " << DP[K][1] << endl;
}
