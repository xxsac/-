//https://www.luogu.com.cn/problem/P2085

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 9;
int a[N][3], ans[N];

int f(int a, int b, int c, int x){
    return a * x * x + b * x + c; 
}

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= 3; ++j)
            cin >> a[i][j];

    priority_queue<int> mx;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int x = f(a[i][1], a[i][2], a[i][3], j);
            if(i == 1) mx.push(x);
            else if(x < mx.top()){
                mx.push(x);
                mx.pop();
            }else break;
        }
    }
    for(int i = 1; i <= m; ++i){
        ans[i] = mx.top();
        mx.pop();
    }
    for(int i = m; i >= 1; --i) cout << ans[i] << ' ';
}