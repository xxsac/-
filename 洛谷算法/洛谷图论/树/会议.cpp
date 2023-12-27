#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e4 + 9;

vector<int> g[N];
int vis[N];
int dis;

void dfs(int u, int dep){
    if(vis[u] == 1) return;
    vis[u] = 1;

    for(auto &e : g[u]){
        if(vis[e]) continue;
        dfs(e, dep + 1);
        dis += (dep + 1);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }

    int isnode = -1, ans = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++i){
        memset(vis, 0, sizeof vis);
        dis = 0;
        dfs(i, 0);
        if(ans > dis){
            ans = dis;
            isnode = i;
        }
    }
    cout << isnode << ' ' << ans;
}

int main(){
    int _ = 1;
    while(_ --) solve();
    return 0;
}
