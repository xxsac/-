//注意邻接表（无向图）

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

bitset<N> vis;
vector<int> g[N];

int n, d; 
int num = 0;

void dfs(int st, int dep){
    if(vis[st] || dep == d) return;
    vis[st] = true;

    for(auto &y : g[st]){
        if(vis[y]) continue;
        dfs(y, dep + 1);
        ++num;
    }
}

void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        if(u ^ v) g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    cout << num;
}

int main(){
    int _ = 1;
    while(_ --) solve();
    return 0;
}
