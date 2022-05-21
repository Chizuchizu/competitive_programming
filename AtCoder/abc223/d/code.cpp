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
        int A, B;
        cin >> A >> B;
        A--; B--;

        G[A].push_back(B);
        indegree[B] += 1;
    }
    
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < N; i++){
        if (indegree[i] == 0){
            heap.push(i);
        }
    }


    vector<int> sorted;

    while (!heap.empty()) {
        int v;
        v = heap.top();
        heap.pop();

        sorted.push_back(v);

        for (int i = 0; i < (int)G[v].size(); i++){
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) {
                heap.push(u);
            }
        }
    }

    if ((int)sorted.size() == N) {
        for (int i = 0; i < N; i++){
            cout << sorted[i] + 1;
            if (i < N - 1) {
                cout << " ";
            }
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }



}
