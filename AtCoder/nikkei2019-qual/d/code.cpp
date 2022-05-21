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
int dep[1001010];
int ans[1001010];    
vector<bool> visited;


int main(){
    cin >> N >> M;

    vector<vector<int>> G(N);
    vector<int> indegree(N);

    visited.resize(N);

    for (int i = 0; i < N + M - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        indegree[b] += 1;
    }


    stack<int> que;
    vector<int> sorted;
    vector<int> parent(N, -1);

    int root = 0;
    
    for (int i = 0; i < N; i++){
        if (indegree[i] == 0) { 
        que.push(i);
            root = i;
        }
    }

    // que.push(root);
    while (!que.empty()) {
        int v = que.top();
        que.pop();

        sorted.push_back(v);
        for (int u: G[v]) {

            indegree[u] -= 1;

            if (indegree[u] == 0){
                que.push(u);
                // parent[u] = i;
            }
        }

    }

    for (int i = 0; i < N; i++){
        int cu = sorted[i];
        for (int to: G[cu]) {
            chmax(
                    dep[to],
                    dep[cu] + 1
                 );
        }
    }
    /*
    for (int i = 0; i < N; i++){
        cout << sorted_vertices[i] + 1 << " ";
    }
    cout << endl;
    */


    root = sorted[0];
    ans[root] = -1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < (int)G[i].size(); j++){
            int to = G[i][j];
            if (dep[i] + 1 == dep[to]) {
                ans[to] = i;
            }
        }
    }
    for (int i = 0; i < N; i++){
        cout << ans[i] + 1 << endl;
    }
}
