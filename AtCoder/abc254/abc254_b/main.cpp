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


int N;
int ANS[100][100];
void solve() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i){
                ANS[i][j] = 1;
            } else {
                ANS[i][j] = ANS[i - 1][j - 1] + ANS[i - 1][j];
            }

            cout << ANS[i][j] << " ";
        }
        cout << endl;
    }


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K][0] << " " << DP[K][1] << endl;
}

