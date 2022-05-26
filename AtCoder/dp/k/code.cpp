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

int N, K;
int A[100];
int DP[100006];

int main(){
    cin >> N >> K;


    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    
    for (int i = 0; i <= K; i++){
        int count = 0;
        int lose = 0;
        for (int j = 0; j < N; j++){
            int a = A[j];
            if (i - a >= 0){
                count ++;
                if (DP[i - a] == 0){
                    lose++;
                }
            }
        }
        if (count == 0){
            DP[i] = 0;
        } else if (0 < lose) {
            DP[i] = 1;
        } else {
            DP[i] = 0;
        }
        //cout << i << " " << DP[i][0] << " " << DP[i][1] << endl;
    }

    //cou << DP[K][0] << " " << DP[K][1] << endl;
    if (DP[K]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
