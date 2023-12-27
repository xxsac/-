//https://www.luogu.com.cn/problem/P2168


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 9;

ll a[N];

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    //中位数即第n / 2小的数，堆维护；
    priority_queue<ll> mx;
    priority_queue<ll, vector<ll>, greater<ll> > mi;
    // 第一次不对mx开放，直接取小堆顶
    // 当mx的数量达到i时，取mx堆顶，弹出mx堆顶
    int p = 1;
    for(int i = 1; i <= n; i += 2){
        for(int j = p; j <= i; ++j){
            mx.push(a[j]);
            if(mx.size() == ( (i + 2 - 1) / 2) ){
                mi.push(mx.top());
                mx.pop();
            }
        }
        cout << mi.top() << '\n';
        mx.push(mi.top());
        mi.pop();
        p = i + 1;
    }
    return 0;
}