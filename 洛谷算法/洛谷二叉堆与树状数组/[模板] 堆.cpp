#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 9;

ll a[N];

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    while(n --){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            pq.push(x);
        }
        if(op == 2){
            cout << pq.top() << '\n';
        }
        if(op == 3){
            pq.pop();
        }
    }
    return 0;
}