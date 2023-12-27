#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 20010;
const ll inf = 4e18, p = 998244353;

int a[N];
int dp[N];

int main(){
    int V, n; cin >> V >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    
    for(int i = 1; i <= n; ++i){
        for(int j = V; j >= a[i]; --j){
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
            
        }
    }
    

    cout <<  V - dp[V] << '\n';
    return 0;
}