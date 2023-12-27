#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105, T = 2e3 + 9;
const ll inf = 4e18;

int a[N];
int dp[T][T];

int main(){
    int m, n; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 0; i <= n; ++i) dp[i][0] = 1; //初始化的问题，当不花钱买第i种物品时，是行得通的，方案数为1

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j >= a[i]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m] << '\n';
}