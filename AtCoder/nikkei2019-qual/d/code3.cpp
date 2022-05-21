#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; } //---------------------------------------------------------------------------------------------------
struct TopologicalSort {
    vector<vector<int>> E; TopologicalSort(int N) { E.resize(N); }
    void add_edge(int a, int b) { E[a].push_back(b); }
    bool visit(int v, vector<int>& order, vector<int>& color) { color[v] = 1;
        for (int u : E[v]) { if (color[u] == 2) continue; if (color[u] == 1) return false;
        if (!visit(u, order, color)) return false; } order.push_back(v); color[v] = 2; return true; }
    bool sort(vector<int> &order) { int n = E.size(); vector<int> color(n);
        for (int u = 0; u < n; u++) if (!color[u] && !visit(u, order, color)) return false;
        reverse(order.begin(), order.end()); return true; } };
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/






int N, M;
vector<int> G[101010];
int dep[101010];
//---------------------------------------------------------------------------------------------------
int ans[101010];
void _main() {
    cin >> N >> M;

    TopologicalSort ts(N);

    rep(i, 0, N + M - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        ts.add_edge(a, b);
    }
    
    vector<int> sorted;
    ts.sort(sorted);
    for (int i = 0; i < N; i++){
	    cout << sorted[i] + 1 << " ";
	}
    cout << endl;
    for (int i = 0; i < N; i++){
        int cu = sorted[i];
        for (int j = 0; j < (int)G[cu].size(); j++){
            chmax(
                    dep[G[cu][j]],
                    dep[cu] + 1
                 );
        }
    }
    for (int i = 0; i < N; i++){
        cout << sorted[i] + 1 << " ";
    }
    cout << endl;
    /*
    for (int i = 0; i < N; i++){
        cout << sorted_vertices[i] + 1 << " ";
    }
    cout << endl;
    */

    for (int i = 0; i < N; i++){
        cout << dep[i] + 1 << " ";
    }
    cout << endl;

    int root = sorted[0];
    ans[root] = -1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < (int)G[i].size(); j++){
            int to = G[i][j];
            if (dep[i] + 1 == dep[j]) {
                ans[to] = i;
            }
        }
    }
    for (int i = 0; i < N; i++){
        cout << ans[i] + 1 << endl;
    }
}

