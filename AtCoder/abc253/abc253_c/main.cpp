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



int Q;
vector<int> HENKAN;

typedef pair<int, int> pi;
multiset<int> ms;

void solve() {
    cin >> Q;

    for (int i = 0; i < Q; i++){
        int op, x, c;
        cin >> op;
        if (op == 1){
            cin >> x;
            ms.insert(x);

            
        } else if (op == 2){
            cin >> x >> c;

            while (true) {
                if (c <= 0) break;
                if (ms.find(x) != ms.end()) {
                    break;
                }

                ms.erase(ms.find(x));
                c--;
            }

        } else {
            int ans = *ms.rbegin() - *ms.begin();
            cout << ans << endl;
        }
  //         cout << " =" << que2.top() << " " << que.top() << endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();

    //cou << DP[K] [0] << " " << DP[K][1] << endl;
}

