#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
const ll inf = 4e18;

ll a[N], prefix[N];

int main(){
    int n; cin >> n;
    int sum = 0, ans = -998244353; //注意数列全为负数的情况
    for(int i = 1; i <= n; ++i){ 
        cin >> a[i];
        if(i == 1) sum = a[i];
        else sum = max(a[i], a[i] + sum);
        ans = max(ans, sum);
    }

    cout << ans << '\n';
}