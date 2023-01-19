#define MOD 1000000007
#include<bits/stdc++.h>
long long int Recur(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    long long ans=(((n-1)%MOD)*(Recur(n-1)%MOD + Recur(n-2)%MOD))%MOD;
    return ans;
}
long long Mem(int n, vector<long long int>&dp){
      if(n==1)return 0;
      if(n==2)return 1;
     if(dp[n]!=-1)return dp[n];
      dp[n]= (((n-1)%MOD)*(Mem(n-1,dp)%MOD + Mem(n-2,dp)%MOD))%MOD;
      return dp[n];
}
long long Tab(int n){
   vector<long long int>dp(n+1,0);
       dp[1]=0;
       dp[2]=1;
    for(int i=3; i<=n; i++){
       dp[i]=(((i-1)%MOD)*(dp[i-1]%MOD + dp[i-2]%MOD))%MOD;
    }
    return dp[n];
}
long long space(int n){
  long long int prev2=0;
    long long int prev1=1;
    for(int i=3; i<=n; i++){
       int ans=(((i-1)%MOD)*(prev1%MOD + prev2%MOD))%MOD;
         prev2=prev1;
         prev1=ans;
    }
    return prev1;

}

long long int countDerangements(int n) {
    //long long ans=Recur(n);
//     vector<long long int>dp(n+1,-1);
//     return Mem(n,dp);
    // Write your code here.
   // return Tab(n);
    return space(n);
}