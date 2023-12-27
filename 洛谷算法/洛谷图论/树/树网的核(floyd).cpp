#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 305, inf = 1e6;

struct Edge{
    ll v, w;
};

vector<Edge> g[N];
int d[N][N];
int n, s; 

void solve(){
    cin >> n >> s;
    memset(d, 0x3f, sizeof d);

    int u, v, w; 
    for(int i = 1; i <= n - 1; ++i){
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        //d[v][u] = d[u][v];
    }

    for(int i = 1; i <= n; ++i) d[i][i] = 0;
    
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    set<int> inpath;
    int dima = 0, st = -1, en = -1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(dima <= d[i][j] && d[i][j] < 0x3f){
                dima = max(dima, d[i][j]);
                inpath.insert(i), inpath.insert(j);
                st = i, en = j;
            }
        }
    }

    int minECC = inf;
    for(auto &i : inpath){
        for(auto &j : inpath){
            if(d[i][j] <= s) minECC = min(minECC, max(d[st][i], d[j][en]));
        }
    }

    cout << minECC;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int _ = 1;
    while(_ --) solve();
    return 0;
}







