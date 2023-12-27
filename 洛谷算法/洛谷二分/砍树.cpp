#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9;
ll a[N];
ll n, m;

int check(ll val){
    //int p = lower_bound(a + 1, a + 1 + n, val) - a;
    ll ans = 0ll;
    for(int i = 1; i <= n; ++i){
        if(a[i] > val) ans += (a[i] - val);
    }
    if(ans < m) return 1;
    else return 0;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);

    ll l = a[1], r = a[n];
    while(l <= r){
        ll val = (l + r) / 2;
        if(check(val)) r = val - 1;
        else l = val + 1;
    } 
    cout << l - 1 << '\n';
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while(_ --) solve();
    return 0;
}