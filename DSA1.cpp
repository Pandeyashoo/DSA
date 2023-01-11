#include <bits/stdc++.h> 
int solve(vector<int>&nums,int n){
   if(n<0)return 0;
    if(n==0)return nums[0];
    int include=solve(nums,n-2)+nums[n];
    int exclude=solve(nums,n-1);
    int ans=max(include,exclude);
    return ans;
}
int solveMem(vector<int>&nums,vector<int>&dp,int n){
      if(n<0)return 0;
     if(n==0)return nums[0];
    if(dp[n]!=-1)return dp[n];
    int include=solveMem(nums,dp,n-2)+nums[n];
    int exclude=solveMem(nums,dp,n-1);
    dp[n]=max(include,exclude);
    return dp[n];
}
int solveTab(vector<int>&nums){
    int n=nums.size();
     vector<int> dp(n+1,0);
        //step 2 :
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        //step 3 :
        for(int i=2; i<n;i++)
        {
            int incl = dp[i-2] + nums[i];
            int excl = dp[i-1] + 0;
            dp[i] = max(incl, excl);
        }
        return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    //int n=nums.size();
   // vector<int>dp(n,-1);
    int ans=solveTab(nums);
    return ans;
}