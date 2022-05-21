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

string S, T;
int DP[3010][3010];

int main(){
    cin >> S >> T;

    int LS = S.length();
    int LT = T.length();


    for (int i = 1; i <= LS; i++){
        for (int j = 1; j <= LT; j++){
            if (S[i-1] == T[j-1]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    

    int length = DP[LS][LT];
    int i = LS;
    int j = LT;
    int k = length;
    
    string ans(length, '0');

    while ( k >= 0 && i > 0 && j > 0 ) {
        if ( DP[i][j] == DP[i - 1][j - 1] ) {
            i--;
            j--;
        } else if ( DP[i][j] == DP[i - 1][j] ) {
            i--;
        } else if ( DP[i][j] == DP[i][j - 1] ) {
            j--;
        } else {
            ans[k-1] = S[i-1];

            i--;
            j--;
            k--;
        }
    }

    cout << ans << endl;

}
