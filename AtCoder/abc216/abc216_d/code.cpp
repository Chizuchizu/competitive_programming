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

int N, M;

int main(){
    cin >> N >> M;

    vector<vector<int>> G(N);
    vector<int> indegree(N);


    for (int i = 0; i < M; i++){
        int k;
        cin >> k;
        int ba = -1;
        for (int  j = 0; j < k; j++){
            int a;
            cin >> a;
            a--;
            if (j != 0) {
                G[a].push_back(ba);
                indegree[ba] += 1;

            }
            ba = a;
        }
    }
    
    queue<int> que;

    for (int i = 0; i < N; i++){
        if (indegree[i] == 0){
            que.push(i);
        }
    }

    vector<int> sorted;

    while (!que.empty()) {
        int v;
        v = que.front();
        que.pop();

        sorted.push_back(v);

        for (int i = 0; i < (int)G[v].size(); i++){
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) {
                que.push(u);
            }
        }
    }

    if ((int)sorted.size() == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }



}
