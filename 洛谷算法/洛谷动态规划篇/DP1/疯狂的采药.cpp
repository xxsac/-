#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9, M = 1e7 + 9;
const ll inf = 4e18;

ll t[N], v[N];
ll dp[M];

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll T, m; cin >> T >> m;
    for(int i = 1; i <= m; ++i) cin >> t[i] >> v[i];

    for(int i = 1; i <= m; ++i){
        for(int j = t[i]; j <= T; ++j){
            if(j >= t[i]) dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
            else dp[j] = dp[j];
        }
    }
    cout << dp[T] << '\n';
}