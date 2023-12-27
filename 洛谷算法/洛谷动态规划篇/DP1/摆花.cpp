#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
const ll inf = 4e18, p = 1e6 + 7;

ll dp[N][N];
ll a[N];

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    dp[0][0] = 1;

    for(ll i = 1; i <= n; ++i){
        for(ll j = 0; j <= m; ++j){
            for(ll k = 0; k <= min(j, a[i]); ++k){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
            }
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}