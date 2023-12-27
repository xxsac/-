#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
const ll inf = 4e18;

ll dp[N][N];

int main(){
    int r; cin >> r;
    
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= i; ++j){
            cin >> dp[i][j];
        }
    }

    for(int i = r-1; i >= 1; --i){
        for(int j = 1; j <= i; ++j){
            int k = j;
            dp[i][j] = max(dp[i][j] + dp[i + 1][k], dp[i][j] + dp[i + 1][k + 1]);
        }
    }    

    cout << dp[1][1] << '\n';
    return 0;
}