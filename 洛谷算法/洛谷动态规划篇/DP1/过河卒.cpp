#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 25;
const ll inf = 4e18;

bool block[N][N];
ll dp[N][N];
ll xe, ye, xh, yh; 

const int wi[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int wj[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main(){
    cin >> xe >> ye >> xh >> yh;
    xe += 2; ye += 2; xh += 2; yh +=2;

    dp[2][1] = 1;
    //block[xh][yh] = 1;
    for(int i = 0; i <= 8; ++i) block[xh + wi[i]][yh + wj[i]] = 1;
    
    for(int i = 2; i <= xe; ++i){
        for(int j = 2; j <= ye; ++j){
            if(block[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[xe][ye] << '\n';
    return 0;
}


