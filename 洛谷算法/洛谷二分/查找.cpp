#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
ll a[N];
ll x; 

int check(ll mid){
    if(x > a[mid]) return 1;
    else return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    while(m --){
        cin >> x;
        ll l = 1, r = n;
        while(l < r){
            ll mid = (l + r) / 2;
            if(check(mid)) l = mid + 1;
            else r = mid; // 注意是mid，不是mid + 1
        }
        cout << (x == a[l] ? l : -1) << ' ';
    }  
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while(_ --) solve();
}