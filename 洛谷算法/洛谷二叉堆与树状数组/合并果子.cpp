//https://www.luogu.com.cn/problem/P1090

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

int main(){
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i = 1; i <= n; ++i){
        ll x; cin >> x;
        pq.push(x); 
    }

    ll ans = 0ll;
    while(pq.size() > 1){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ll x = a + b;
        ans += x;
        pq.push(x);
    }
    cout << ans << '\n';
    return 0;
}