#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 25;
const ll inf = 4e18;

int val[N];

bool link[N][N];

vector<int> g[N];
int dp[N][N];

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> val[i];

    memset(g, -1, sizeof g);
    
    for(int i = 1; i <= n - 1; ++i){
        for(int j = i + 1; j <= n; ++j){
            int x; cin >> x;
            if(x){
                g[i].push_back(j);
                g[j].push_back(i);
            }
            else continue;
        }
    }
    
    for(int i = 1; i <= n; ++i){
        dp[i][i] = val[i];
    }
    int ans = 0;
    for(int u = 1; u <= n - 1; ++u){
        for(auto &v : g[u]){
            dp[u][v] = max(dp[][], dp[u][v - 1] + val[v - 1]);
        }
    }

    cout << ans << '\n';
    return 0;
}



