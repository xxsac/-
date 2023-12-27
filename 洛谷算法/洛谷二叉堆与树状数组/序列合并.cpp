//https://www.luogu.com.cn/problem/P1631

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;
ll a[N], b[N], ans[N];

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    priority_queue<ll> mx;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == 1){
                mx.push(a[i] + b[j]);
            }else{
                ll x = a[i] + b[j];
                if(x < mx.top()){
                    mx.push(a[i] + b[j]);
                    mx.pop();
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        ans[i] = mx.top();
        mx.pop();
    }
    for(int i = n; i >=1 ; --i){
        cout << ans[i] << ' ';
    }
    return 0;
}