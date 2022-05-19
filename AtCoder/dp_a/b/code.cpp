#include <bits/stdc++.h>
using namespace std;

#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int N, K;
int H[100100]; 
int DP[101500];

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> H[i];
        // cout << H[i] << endl;
    }
    for (int i = 0; i < 101500; i++){
        DP[i] = INF32;
    }

    DP[0] = 0;
    //DP[1] = abs(H[1] - H[0]);
    for (int i = 0; i < N; i++){
        for (int j = 1; j <= K; j++){
            DP[i + j] = min(
                        DP[i + j],
                        abs(H[i] - H[i + j]) + DP[i]
                    );
        }
    } 
    cout << DP[N - 1] << endl;


}
