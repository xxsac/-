#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 9;
const ll inf = 4e18, p = 80112002;

ll dp[N];

vector<int> g[N];
bitset<N> vis;
ll len = 0, ans = 0;
int n, m; 

void dfs(int x){

    vis[x] = true;
    if(vis[x]) return;
    len = len + 1 % p;
    for(auto &y : g[x]){
        dfs(y);
    }

}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    dfs(1);
    cout << len << '\n';
    return 0;
}