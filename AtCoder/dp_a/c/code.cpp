#include <bits/stdc++.h>
using namespace std;

#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int N;
int A[101000], B[101000], C[101000];
int DP[3][101000];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
        // cout << H[i] << endl;
    }

    DP[0][0] = A[0];
    DP[1][0] = B[0];
    DP[2][0] = C[0];
    //DP[1] = abs(H[1] - H[0]);
    for (int i = 1; i < N; i++){
        DP[0][i] = max(
                    DP[1][i - 1], DP[2][i - 1]
                ) + A[i];
        DP[1][i] = max(
                    DP[0][i - 1], DP[2][i - 1]
                ) + B[i];
        DP[2][i] = max(
                    DP[0][i - 1], DP[1][i - 1]
                ) + C[i];
    } 

    int tmp = max(DP[0][N - 1] , DP[1][N - 1]);
    tmp = max(tmp, DP[2][N-1]);
    cout << tmp << endl;
}
