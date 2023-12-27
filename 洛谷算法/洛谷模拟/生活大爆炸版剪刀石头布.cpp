#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

int OPofwinner(int a, int b){

    if(a == 0){
        if(b == 0) return 13;
        if(b == 1) return b;
        if(b == 2) return a;
        if(b == 3) return a;
        if(b == 4) return b;
    }
    if(a == 1){
        if(b == 0) return a;
        if(b == 1) return 13;
        if(b == 2) return b;
        if(b == 3) return a;
        if(b == 4) return b;
    }
    if(a == 2){
        if(b == 0) return b;
        if(b == 1) return a;
        if(b == 2) return 13;
        if(b == 3) return b;
        if(b == 4) return a;
    }
    if(a == 3){
        if(b == 0) return b;
        if(b == 1) return b;
        if(b == 2) return a;
        if(b == 3) return 13;
        if(b == 4) return a;
    }
    if(a == 4){
        if(b == 0) return a;
        if(b == 1) return a;
        if(b == 2) return b;
        if(b == 3) return b;
        if(b == 4) return 13;
    }
}

void solve(){
    int N, A, B; cin >> N >> A >> B;
    deque<int> a;
    deque<int> b;
    for(int i = 1; i <= A; ++i){
        int x; cin >> x;
        a.push_back(x);
    }
    for(int i = 1; i <= B; ++i){
        int x; cin >> x;
        b.push_back(x);
    }
    int ca = 0, cb = 0;
    while(N){
        int o1 = a.front();
        a.pop_front(), a.push_back(o1);
        int o2 = b.front();
        b.pop_front(), b.push_back(o2);

        int op = OPofwinner(o1, o2);
        if(o1 == op) ++ca;
        else if(o2 == op) ++cb;
        --N;
    }
    cout << ca << ' ' << cb << '\n';
}

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while(_ --) solve();
    return 0;
}




