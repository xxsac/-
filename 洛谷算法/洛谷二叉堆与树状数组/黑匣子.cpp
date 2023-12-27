//https://www.luogu.com.cn/problem/P1801


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

ll a[N], u[N];
ll box[N];

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin >> m >> n;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    
    priority_queue<ll, vector<ll>, greater<ll> > mi;
    priority_queue<ll> mx; 

    int p = 1;
    ll x;
    for(int i = 1; i <= n; ++i){
        int u; cin >> u;
        for(int j = p; j <= u; ++j){
            mx.push(a[j]);
            if(mx.size() == i){
                x = mx.top();
                mi.push(x);
                mx.pop();
            }
        }
        cout << mi.top() << '\n';
        mx.push(mi.top());
        mi.pop();
        p = u + 1;
    }
    return 0;
}