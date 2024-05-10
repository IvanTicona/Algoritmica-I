#include<bits/stdc++.h>

#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

using namespace std;

int coins[3] = { 2, 3 , 5};
int dp[100000];

int f(int n) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    if(dp[n] == -1) { // alguna vez no he calculado el valor de f(n)
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            ans += f(n - coins[i]); 
            // print
        }
        dp[n] = ans;
    }
    return dp[n];
}

// bottom up 
int bottomUp[4][1000];
int f2(int n) {
    bottomUp[0][0] = 1;
    for(int i = 1; i <= 3; i++) {// 2, 3, 5
        bottomUp[i][0] = 1;
        for(int j = 1; j <= n; j++) { // 1 ==> 15
            bottomUp[i][j] = bottomUp[i-1][j];
            if(j - coins[i-1] >= 0) {
                bottomUp[i][j] += bottomUp[i][j - coins[i-1]];
            }
        }
    }
    return bottomUp[3][n];
}

// con un arreglo de una dimension
int dp3[1000];
int f3(int n) {
    dp3[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp3[i] = 0;
        for(int j = 0; j < 3; j++) {
            if(i - coins[j] >= 0) {
                dp3[i] += dp3[i - coins[j]];
            }
        }
    }
    return dp3[n];
}



int main() {
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<f2(n)<<endl;
}