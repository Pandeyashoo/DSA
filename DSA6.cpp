#include <bits/stdc++.h>
int recur(vector<int>&num, int tar){
    if(tar==0)return 1;
    if(tar<0)return 0;
    int ans=0;
    for(int i=0; i<num.size(); i++){
         ans+=recur(num,tar-num[i]);
    }
    return ans;
} 
int Mem(vector<int>&num,int tar,vector<int>&dp){
    if(tar==0)return 1;
    if(tar<0)return 0;
    int ans=0;
    if(dp[tar]!=-1)return dp[tar];
    for(int i=0; i<num.size(); i++){
         ans+=Mem(num,tar-num[i],dp);
    }
    dp[tar]=ans;
    return dp[tar];
}
int Tab(vector<int>&num,int tar){
    vector<int>dp(tar+1,-1);
    dp[0]=1;
    for(int i=1;i<tar+1;i++){
        for(int j=0; j<num.size(); j++){
            dp[i]=tar-num[j];
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{ 
   // int ans=recur(num,tar);
   vector<int>dp(tar+1,-1);
   int ans=Mem(num,tar,dp);
    return ans;
    int ans2=Tab(num,tar);
    return ans2;
    
}