#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
const ll inf = 4e18;

ll l[N], w[N], u[N];

ll dp[N][N];

int main(){
    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> l[i] >> w[i] >> u[i];
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= x; ++j){
            if(j >= u[i]) dp[i][j] = max(dp[i - 1][j] + l[i], dp[i - 1][j - u[i]] + w[i]);
            else dp[i][j] = dp[i - 1][j] + l[i];
        } 
    }


    cout << 5 * dp[n][x] << '\n';
    return 0;
}







