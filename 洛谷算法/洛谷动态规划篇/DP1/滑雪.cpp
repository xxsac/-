#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;

struct Node{
    int i, j, num;

    bool operator < (const Node &e)const{
        return num > e.num;
    }
};

int a[N][N], dp[N][N];

int main(){
    priority_queue<Node> pq;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j) cin >> a[i][j], pq.push({i, j, a[i][j]});
    }
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) dp[i][j] = 1;

    while(pq.size()){
        auto x = pq.top(); pq.pop();
        int i = x.i, j = x.j;

        if(a[i - 1][j] < x.num) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        if(a[i + 1][j] < x.num) dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1); 
        if(a[i][j - 1] < x.num) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1); 
        if(a[i][j + 1] < x.num) dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1); 
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}