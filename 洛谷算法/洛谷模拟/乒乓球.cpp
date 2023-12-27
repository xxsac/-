#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int n;
char s[N];

void match(int mx){
    int my = 0, opo = 0;
    for(int i = 0; i < n; ++i){
        my += (s[i] == 'W');
        opo += (s[i] == 'L');

        if((my >= mx || opo >= mx) && abs(my - opo) >= 2){
            cout << my << ":" << opo << '\n';
            my = 0, opo = 0;
        }
    }

    cout << my << ":" << opo << '\n';
}

void solve(){
    n = 0;
    char sb;
    while(cin >> sb && sb != 'E'){
        if(sb == 'W' || sb == 'L') s[n++] = sb;
    }
    
    match(11);
    cout << '\n';
    match(21);
}

int main(){
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while(_ --) solve();
    return 0;
}




