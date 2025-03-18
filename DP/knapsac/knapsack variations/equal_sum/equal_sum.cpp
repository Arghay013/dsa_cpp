#include <bits/stdc++.h>
using namespace std;
int val[1005];
int dp[1005][1005];
bool subset_sum(int i, int sum){
    if(i<0){
        if(sum == 0) return 1;
        return 0;
    }
    if(dp[i][sum] != -1) return dp[i][sum];
    if(val[i] <= sum){
        bool op1 = subset_sum(i-1, sum-val[i]);
        bool op2 = subset_sum(i-1, sum);
        dp[i][sum] = op1 || op2;
        return dp[i][sum];
    }else{
        dp[i][sum] = subset_sum(i-1, sum);
        return dp[i][sum];
    }
    
}


int main() {
    int n;
    int sum=0;
    cin >> n;
    for(int i = 0; i < n; i++){ cin >> val[i]; sum += val[i]; }

    if(sum%2 == 1){
        cout<<"not possible\n";
    }else{
        for(int i=0; i<=n; i++)
            for(int j=0; j<=sum; j++)
                dp[i][j] = -1;
        if(subset_sum(n-1, sum/2))cout<<"possible\n";
        else cout<<"not possible\n";
    }
    return 0;
}