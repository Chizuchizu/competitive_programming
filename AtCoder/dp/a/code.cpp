#include <bits/stdc++.h>
using namespace std;


int N;
int H[100010]; 
int DP[10010];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> H[i];
        // cout << H[i] << endl;
    }

    DP[0] = 0;
    DP[1] = abs(H[1] - H[0]);
    for (int i = 2; i < N; i++){
        DP[i] = min(
                    abs(H[i] - H[i - 1]) + DP[i - 1],
                    abs(H[i] - H[i - 2]) + DP[i - 2]
                );
    } 
    cout << DP[N - 1] << endl;


}
