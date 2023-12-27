#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
const ll inf = 4e18;

ll dp[N][N];
ll t[N], v[N];

int main(){
    int T, M; cin >> T >> M;
    for(int i = 1; i <= M; ++i) cin >> t[i] >> v[i];

    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= T; ++j){
            if(j >= t[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[M][T] << '\n';
    return 0;
}