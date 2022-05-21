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


vector<int> topological_sort(
            vector<vector<int>> &G,
            vector<int> &indegree,
            int V
        ) {
    vector<int> sorted_vertices;

    // 次数が0の頂点をqueに追加
    queue<int> que;
    for (int i = 0; i < V; i++){
        if (indegree[i] == 0) {
            que.push(i);
        } 
    }


    while (!que.empty()) {
        int v;

        v = que.front();
        que.pop();

        sorted_vertices.push_back(v);

        for (int i = 0; i < G[v].size(); i++){
            int u = G[v][i];
            indegree[u] -= 1;

            if (indegree[u] == 0) {
                que.push(u);
            } 
        }

    }

    return sorted_vertices;
}

int N, M;
int DP[3010][3010];
vector<bool> visited;


int main(){
    cin >> N >> M;

    vector<vector<int>> G(N);
    vector<int> indegree(N);

    visited.resize(N);

    for (int i = 1; i < N + M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        G[a].push_back(b);
        indegree[b] += 1;
    }

    
    vector<int> sorted_vertices = topological_sort(
                G,
                indegree,
                N
            );
    
    /*
    cout << sorted_vertices.size() << endl;

    for (int i= 0; i<N;i++){
        cout << sorted_vertices[i] + 1 << " ";
    }
    */
    
    for (int i= 0; i<N;i++){
        int idx=-1, u=-1;
        for (int j = 0; j < N; j++){
            for (int k = 0; k < G[j].size(); k++){
                if (G[j][k] == i) {
                    int dx = (int)(find(sorted_vertices.begin(), sorted_vertices.end(), j) - sorted_vertices.begin());
                    // cout << dx << endl;
                    if ( sorted_vertices[dx] != j ) continue;
                    if ( dx > idx ) {
                        idx = (int)(find(sorted_vertices.begin(), sorted_vertices.end(), j) - sorted_vertices.begin());
                        u = j;
                    }
                }
            }
        }
        cout << u + 1  << endl;
    }

}
