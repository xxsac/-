#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll a[N];
ll x; 

void solve(){
    ll n, c; cin >> n >> c;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        // upper_bound(x)返回第一个 大于x 的位置, lower_bound(x)返回第一个 大于等于x 的位置
        ans += (upper_bound(a + 1, a + 1 + n, a[i] + c) - a) - (lower_bound(a + 1, a + 1 + n, a[i] + c) - a);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while(_ --) solve();
}